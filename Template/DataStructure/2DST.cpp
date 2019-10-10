namespace ST_2D{
	const int N = 1010, M = 11;
	int Log[N], p[M], dep1, dep2;
	short st[M][M][N][N];
	void build(int n, int m, short a[][N]){
		rep(i, 0, M) p[i] = 1 << i;
		rep(i, 2, N) Log[i] = Log[i >> 1] + 1;
		for(dep1 = 0; (1 << dep1) < n; dep1++);
		for(dep2 = 0; (1 << dep2) < m; dep2++);
		rep(i, 1, n + 1) rep(j, 1, m + 1) 
			st[0][0][i][j] = a[i][j]; // modify
		rep(i, 1, n + 1) rep(j, 1, dep2 + 1) rep(k, p[j], m + 1)
			st[0][j][i][k] = max(st[0][j-1][i][k], st[0][j-1][i][k - p[j-1]]);
		//attention to range of k
		rep(i, 1, dep1+1) rep(j, p[i], n+1) rep(k, 0, dep2+1) rep(l, p[k], m+1)
			st[i][k][j][l]=max(st[i-1][k][j-p[i-1]][l], st[i-1][k][j][l]);
	}
	int qry(int x1, int y1, int x2, int y2){
		int l1 = Log[x2-x1+1], l2 = Log[y2-y1+1];
		int res1 = max(st[l1][l2][x1+p[l1]-1][y1+p[l2]-1], st[l1][l2][x2][y2]);
		int res2 = max(st[l1][l2][x1+p[l1]-1][y2], st[l1][l2][x2][y1+p[l2]-1]);
		return max(res1, res2);
	}
}
