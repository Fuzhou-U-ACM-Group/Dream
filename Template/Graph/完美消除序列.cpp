const int N = 1e5 + 7, M = 2e6 + 7;
int ans, use[N], col[N], lab[N], vis[N], a[N], e, m, ne[M], h[N], to[M], u, v, n, ma;
vi g[N];

void ins(int p, int v) { ++e; to[e] = v; ne[e] = h[p]; h[p] = e; }
void del(int p) {
	h[p] = ne[h[p]];
	while (!h[ma]) ma--;
}
int solve(){
	cin >> n >> m;
	rep(i, 0, m) {
		cin >> u >> v;
		g[u].pb(v); g[v].pb(u);
	}
	e = ma = 0;  // 完美消除序列 
	rep(i, 1, n+1) ins(0, i);
	per(i, 1, n+1) {
		while (1) {
			u = to[h[ma]]; del(ma);
			if (!vis[u]) break;
		}
		a[i] = u, vis[u] = 1;
		for (auto v : g[u]) {
			ins(++lab[v], v);
			ma = max(lab[v], ma);
		}
	} ans = 0;
	per(i, 1, n+1) {  // 色数 
		for (auto v : g[a[i]]) use[col[v]] = i;
		rep(j, 1, n+1) if (use[j] != i) {
			col[a[i]] = j;
			ans = max(ans, col[a[i]]);
			break;
		}
	}
	return ans;
}
