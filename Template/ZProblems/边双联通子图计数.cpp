// 求边双联通子图个数 
const int N = 1 << 10;
int n, S, e[N][N], way[N][N], a[100], t, x, y, dc[N], c[N], c2[N], c1[N], pw2[500], T, m, u, v;
// c 联通子图个数
// dc 不联通子图个数
// c1 单联通子图个数
// c2 边双联通子图个数 
void solve1() {
	S = pw(n) - 1;
	rep(i, 0, S+1) rep(j, 0, S+1) {
		e[i][j] = 0;
		rep(k, 0, n) if (pw(k) & i) e[i][j] += __builtin_popcount(a[k] & j);
	}
	rep(i, 1, S+1) {
		dc[i] = 0;
		for (int msk = (i - 1) & i; msk >= 0; msk = (msk - 1) & i) {
			if (msk & lb(i)) dc[i] = add(dc[i], mul(c[msk], pw2[e[i ^ msk][i ^ msk] / 2]));
			if (msk == 0) break;
		}
		c[i] = sub(pw2[e[i][i] / 2], dc[i]); 
	}
}
void solve2() {
	rep(j, 1, S+1) way[0][j] = 1;
	rep(i, 1, S+1) rep(j, 1, S+1) {
		if ((j & i) || lb(j) > lb(i)) continue;
		way[i][j] = 0;
		for (int msk = i; msk >= 0; msk = (msk - 1) & i) {
			if (msk & lb(i)) way[i][j] = add(way[i][j], mul(mul(way[i ^ msk][j], c[msk]), e[msk][j]));
			if (msk == 0) break;
		}
	}	
	rep(i, 1, S+1) {
		c1[i] = 0;	
		for (int msk = (i - 1) & i; msk >= 0; msk = (msk - 1) & i) {
			if (msk & lb(i)) c1[i] = add(c1[i], mul(way[i ^ msk][msk], c2[msk]));
			if (msk == 0) break;
		}
		c2[i] = sub(c[i], c1[i]);
	}
}
int main() {
	cin >> T;
	pw2[0] = 1;
	rep(i, 1, 300) pw2[i] = pw2[i-1] * 2 % P;
	rep(cas, 0, T) {
		cin >> n >> m;
		rep(i, 0, n) a[i] = (pw(n) - 1) ^ pw(i);
		rep(i, 0, m) {
			cin >> u >> v;
			u--;v--;
			a[u] ^= pw(v);
			a[v] ^= pw(u);
		}
		solve1();
		solve2();
		cout << c2[S] << endl;
	}
	return 0;
}