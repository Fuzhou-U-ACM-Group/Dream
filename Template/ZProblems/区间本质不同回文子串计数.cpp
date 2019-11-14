namespace Space {
	const int N = 600005;
	char s[N]; int m, n, l, r; ll ans = 0, ret[N]; vector<pii> Q[N];
	struct SegTree {
		int a[N << 2];
		int query(int x, int l, int r, int fl, int fr) {
			if (l == fl && r == fr) return a[x];
			int t = (l + r) >> 1;
			if (fr <= t) return query(x << 1, l, t, fl, fr); 
			else if (fl > t) return query(x << 1 | 1, t + 1, r, fl, fr); 
			else return max(query(x << 1, l, t, fl, t), query(x << 1 | 1, t + 1, r, t + 1, fr));
		}
		void updata(int x, int l, int r, int pos, int y) {
			if (l == r) { a[x] = y; return; }
			int t = (l + r) >> 1;
			if (pos <= t)  updata(x << 1, l, t, pos, y); 
			else updata(x << 1 | 1, t + 1, r, pos, y);
			a[x] = max(a[x << 1], a[x << 1 | 1]);
		}
	}Seg;
	struct BIT {
		int d[N];
		void updata(int x, int y) { for (int i = x; i < N; i += i&-i)d[i] += y; }
		int sum(int x) { 
			int res = 0; for (int i = x; i; i -= i&-i)res += d[i]; 
			return res; 
		}
	}BT;
	struct PAM {
		int next[N][26], fail[N], len[N], s[N], id[N], last, n, p;
		int in[N], out[N], d[N], up[N], dfn = 0;
		vector<int> G[N];    // dfs 序
							 // r 为结尾的回文串的长度一定可以分成 logn 段等差数列
		inline int newnode(int l) {
			for (int i = 0; i < 26; ++i) next[p][i] = 0;
			len[p] = l;
			return p++;
		}
		inline void init() {
			p = 0; newnode(0); newnode(-1);
			last = n = 0; s[n] = -1; fail[0] = 1;
		}
		inline int get_fail(int x) {
			while (s[n - len[x] - 1] != s[n]) x = fail[x];
			return x;
		}
		inline void add(int c, int cc) {
			c -= 'a';
			s[++n] = c;
			int cur = get_fail(last);
			if (!next[cur][c]) {
				int now = newnode(len[cur] + 2);
				fail[now] = next[get_fail(fail[cur])][c];
				next[cur][c] = now;
				d[now] = len[now] - len[fail[now]];
				up[now] = (d[fail[now]] == d[now] ? up[fail[now]] : now);
			}
			last = next[cur][c];
			id[cc] = last;
		}
		void build() { for (int i = 0; i < p; i++)if (i != 1) G[fail[i]].pb(i); }
		void dfs(int x = 1) {
			in[x] = ++dfn;
			for (auto i : G[x]) dfs(i);
			out[x] = dfn;
		}
		void solve() {
			for (int i = 1; i <= n; i++) {
				for (int j = id[i]; j; j = fail[up[j]]) {
					int l = max(1, Seg.query(1, 1, dfn, in[j], out[j]) - len[j] + 2);
					int r = i - len[up[j]] + 2;
					BT.updata(l, 1); BT.updata(r, -1);
				}
				Seg.updata(1, 1, dfn, in[id[i]], i);
				for (auto j : Q[i]) ret[j.se] = BT.sum(j.fi);
			}
		}
	} A;
	void work(int n, int m) {
		scanf("%s", s + 1);
		A.init();
		for (int i = 1; i <= n; i++) A.add(s[i], i);
		A.build();
		A.dfs();
		for (int i = 1; i <= m; i++) scanf("%d%d", &l, &r), Q[r].pb(mp(l, i));
		A.solve();
	}
}
int n, m, l, r;
int main() {
	scanf("%d%d", &n, &m);
	Space::work(n, m);
	rep(i, 1, m + 1) printf("%lld\n", Space::ret[i]);
	return 0;
}
/*
注：离线算法, O(nlogn^2) , 下标从 1 开始

12 5
abcddcbaabcd
1 2
1 4
1 8
4 8
1 12

2
4
8
5
12
*/
