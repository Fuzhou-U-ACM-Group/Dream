struct PAM {
	const int K = 11, N = ::N * K, M = 26;
	int s[N], len[N], ne[N][M], fail[N], cnt[N][K], dep[N], id[N], no[N], last, n, p, cs;
	inline int newnode(int l) { 
		fill_n(ne[p], M, 0);
		fill_n(cnt[p], K, 0);
		dep[p] = 0; len[p] = l;
		return p++;
	}
	inline void init() { newnode(p = 0), newnode(s[0] = -1), fail[last = n = 0] = 1; cs = 0; }
	inline int getfail(int x) { 
		while(s[n - len[x] - 1] != s[n]) x = fail[x]; 
		return x; 
	}
	inline void add(int c) {
		if(c < 0) { s[++n] = c; last = 1; return; }
		s[++n] = c;
		int cur = getfail(last);
		if(!ne[cur][c]) {
			int now = newnode(len[cur] + 2);
			fail[now] = ne[getfail(fail[cur])][c];
			ne[cur][c] = now;
			dep[now] = dep[fail[now]] + 1; 
		}
		last = ne[cur][c], cnt[last][cs]++; 
		id[n] = last, no[last] = n; 
	}
	inline void ins() {
		for(all string) {
			++cs; add(- cs - 1);
			for(all char) add(char);
		}
	}
	inline void build() { per(i, 0, p) rep(j, 0, cs) cnt[fail[i]][j] += cnt[i][j]; }
};
