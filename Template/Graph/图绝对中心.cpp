// id : 0 .. n - 1
// time : O(n ^ 3)
// g[i][i] should be 0

const int N = 1e3 + 7, inf = 1e9 + 7;
int n, m, g[N][N], u, v, w;

pii GraphCenter(int n, int g[][N]) {
	static int rk[N][N], d[N][N];
	rep(i, 0, n) rep(j, 0, n) d[i][j] = g[i][j], rk[i][j] = j;
	rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) 
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	rep(i, 0, n) sort(rk[i], rk[i] + n, [&](int a, int b) {return d[i][a] < d[i][b];});
	int ret = inf, s1 = -1, s2 = -1;
	db ds1 = 0, ds2 = 0;
	rep(u, 0, n) {
		if (d[u][rk[u][n - 1]] * 2 < ret) {
			ret = d[u][rk[u][n - 1]] * 2;
			s1 = s2 = u;
			ds1 = ds2 = 0;
		}
		rep(v, 0, n) if (g[u][v] != inf) {
			for (int k = n - 1, i = n - 2; i >= 0; --i) {
				int x = rk[u][i], y = rk[u][k]; 
				if (d[v][x] > d[v][y]) {
					int tmp = d[u][x] + d[v][y] + g[u][v];
					if (tmp < ret) {
						ret = tmp, s1 = u, s2 = v;
						ds1 = 0.5 * tmp - d[u][x];
						ds2 = g[u][v] - ds1;
					}
					k = i;
				}
			}
		}
	}
	cout << ret / 2.0 << endl;
	return mp(s1, s2);
}
