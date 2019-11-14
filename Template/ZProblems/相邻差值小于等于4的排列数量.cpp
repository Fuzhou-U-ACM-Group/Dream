// 求相邻差值小于等于 k(k<=4) 的排列数量
// 一种枚举排列的方法 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse2")
#pragma GCC optimize("unroll-loops")
const int N = 10;
int n, k, a[N], b[N], ok, p, ans, c[200], ans2, S, m; bool o; map<vi, int> f[2][4];
int main() {
	while (cin >> n >> k) {
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		rep(i, 0, 2) rep(j, 0, 4) f[i][j].clear();
		f[0][0][vi()] = 1; o = 0;
		rep(i, 1, n+1) {
			o ^= 1;
			rep(t, 0, 4) f[o][t].clear();
			rep(t, 0, 4) {
				for (auto v : f[!o][t]) {
					m = sz(v.fi); vi a = v.fi;
					rep(l, 0, m) {
						if (l == 0 && (t & 1)) continue;
						if (l == m - 1 && (t & 2)) continue;
						a[l]++;
					} 
					rep(l, 0, m) { // 放左或右 
						if (l == 0 && (t & 1)) continue;
						if (l == m - 1 && (t & 2)) continue;
						vi tmp = a; tmp[l] = 0; p = 1;
						rep(i, 0, sz(tmp)) if (tmp[i]+1 > k) p = 0;
						if (!p) continue;
						(f[o][t][tmp] += v.se) %= P;
						if (l == 0) (f[o][t | 1][tmp] += v.se) %= P;
						if (l == m - 1) (f[o][t | 2][tmp] += v.se) %= P;	
					}
					for (int l = 0; l <= m; l += 2) { // 新开区间 
						if (l == 0 && (t & 1)) continue;
						if (l == m && (t & 2)) continue;
						vi tmp;
						rep(j, 0, l) tmp.pb(a[j]); tmp.pb(0); tmp.pb(0);
						rep(j, l, m) tmp.pb(a[j]);
						p = 1;
						rep(i, 0, sz(tmp)) if (tmp[i]+1 > k) p = 0;
						if (!p) continue;
						(f[o][t][tmp] += v.se) %= P;
						if (l == 0) (f[o][t | 1][tmp] += v.se) %= P;
						if (l == m) (f[o][t | 2][tmp] += v.se) %= P;
					}
					for (int l = 1; l <= m - 2; l += 2) { // 合并区间 
						vi tmp;
						rep(j, 0, l) tmp.pb(a[j]);
						rep(j, l+2, m) tmp.pb(a[j]);
						p = 1;
						rep(i, 0, sz(tmp)) if (tmp[i]+1 > k) p = 0;
						if (!p) continue;
						(f[o][t][tmp] += v.se) %= P;
					}
				}
			}
		}
		ans = 0;
		for (auto v : f[o][3]) if (sz(v.fi) == 2) ans = add(ans, v.se);
		cout << ans << endl;
	}
	return 0;
}
