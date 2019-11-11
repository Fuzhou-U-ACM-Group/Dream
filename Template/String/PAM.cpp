// [0,p) , 0(even) and 1(odd) is virtual , init!!
struct PAM {
	static const int N = ::N, M = 26;
	int s[N], len[N], ne[N][M], fail[N], cnt[N], dep[N], id[N], no[N], last, n, p;
	inline int newnode(int l) { fill_n(ne[p], M, 0); cnt[p] = dep[p] = 0; len[p] = l; return p++; }
	inline void init() { newnode(p = 0), newnode(s[0] = -1), fail[last = n = 0] = 1; }
	inline int getfail(int x) { 
		while(s[n - len[x] - 1] != s[n]) x = fail[x]; 
		return x; 
	}
	inline void add(int c) {
		s[++n] = c;
		int cur = getfail(last);
		if(!ne[cur][c]) {
			int now = newnode(len[cur] + 2);
			fail[now] = ne[getfail(fail[cur])][c];
			ne[cur][c] = now;
			dep[now] = dep[fail[now]] + 1;
		}
		last = ne[cur][c], cnt[last]++; 
		id[n] = last, no[last] = n; 
	}
	inline void build() { per(i, 0, p) cnt[fail[i]] += cnt[i]; }
};
