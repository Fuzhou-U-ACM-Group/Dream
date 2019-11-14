// n 点 m 边强连通子图计数
// 首先要会 n 点 m 边 DAG 计数，然后把枚举出度为零的点集容斥改为枚举缩点后出度为零的点集容斥
const int N = 1 << 15;
int n, cnt[N], S, g[N], f[N], u, v, a[N], m, p[300];
int get(int x) {
	int res = 0;
	while (x) {
		res++;
		x = (x - 1) & x;
	}
	return res;
}
int cal(int x, int y) {
	int res = 0, t;
	while (x) {
		t = x & (-x);
		res += cnt[a[t] & y];
		x ^= t;
	} 
	return res;
}
int main() {
	cin >> n >> m;
	rep(i, 1, m+1) {
		cin >> u >> v;
		a[pw(u-1)] |= pw(v-1);
	}
	S = pw(n) - 1;
	rep(i, 1, S+1) cnt[i] = get(i);
	p[0] = 1;
	rep(i, 1, m+1) p[i] = mul(p[i-1], 2); 
	rep(i, 1, S+1) {
		u = i & (-i);
		for (int x = (i - 1) & i; x > 0; x = (x - 1) & i) {
			if (x & u) g[i] = sub(g[i], mul(f[x], g[i ^ x]));
		}
		f[i] = p[cal(i, i)];
		for (int x = i; x > 0; x = (x - 1) & i) {
			f[i] = sub(f[i], mul(g[x], p[cal(i ^ x, i)]));
		}
		g[i] = add(g[i], f[i]);
	}
	cout << f[S];
	return 0;
}