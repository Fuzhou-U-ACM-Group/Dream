const int M = 26;
struct PAM {
	int s[N], len[N], next[N][M], fail[N], cnt[N], id[N], no[N], pre[N], qlink[N], dep[N], last, n, p, cur, now; ll ans;
	inline int new_node(int _l) { mem(next[p], 0); cnt[p] = dep[p] = 0, len[p] = _l; qlink[p] = 0; return p++; }
	inline void Init() { new_node(p = 0), new_node(s[0] = -1), fail[last = n = 0] = 1; /* ... */ }
	inline bool ok(int x, int y, int d = 0) { return s[n - len[x] - d] == s[n - len[y]]; }
	inline int get_fail(int x) { for (; !ok(x, 0, 1); x = qlink[x]) if (ok(fail[x], 0, 1)) return fail[x]; return x; }
	inline void I(int c) {
		c -= 'a', s[++n] = c, cur = get_fail(last);
		if (!next[cur][c]) {
			now = new_node(len[cur] + 2);
			fail[now] = next[get_fail(fail[cur])][c];
			next[cur][c] = now; pre[now] = cur;
			dep[now] = dep[fail[now]] + 1; //...
			if (len[now] > 1) qlink[now] = ok(fail[now], fail[fail[now]]) ? qlink[fail[now]] : fail[fail[now]];
		}
		last = next[cur][c], cnt[last]++; id[n] = last, no[last] = n; //...
	}
	inline void D() { if (p <= 1) return; if (!(--cnt[last])) next[pre[last]][s[n]] = 0, --p; last = id[--n]; }
	inline void Insert(char s[], int op = 0, int _n = 0) {
		if (!_n) _n = strlen(s);  if (!op) rep(i, 0, _n) I(s[i]); else per(i, 0, _n) I(s[i]);
	}
	inline void count() { per(i, 0, p) cnt[fail[i]] += cnt[i]; }
	inline void Q() { /*count();*/ }
};

/*

注：

1) 此模板如果不使用回退操作，总复杂度仍为线性 ，单次插入不超过 log(n) ，回退操作总是常数

2) 若有回退操作，总复杂度退化；使用可持久化线段树优化的 dLink 链接，单次插入可降为 log 字符集

*/