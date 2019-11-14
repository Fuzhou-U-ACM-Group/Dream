/*
 * 三元闭包边计数
 * 染色 : 能用 A ， B ， C 三种颜色染色，满足对所有边 u->v 有 v 的颜色是 u 的下一种颜色
 * 对每一个弱连通子图：
 * 1. 如果能染色且没用够三种颜色，不能增加边
 * 2. 如果能染色且用了三种颜色，把点按颜色分为三类，三类点中相邻两类都有边 
 * 3. 如果不能染色，所有点之间都有边
 */
const int P = 1e9 + 7, N = 1e5 + 8;
int add(int a, int b) {if((a += b) >= P) a -= P; return a < 0 ? a + P : a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
bool ok; int vis[N], n, m, u, v; ll use[N], ans; vi g[N], gg[N], tmp;
int inc(int x) {
	x++;
	if (x == 4) x = 1;
	return x;
}
int dec(int x) {
	x--;
	if (x == 0) x = 3;
	return x;
}
void dfs(int u) {
	tmp.pb(u);
	for (auto v : g[u]) {
		if (!vis[v]) {
			vis[v] = inc(vis[u]);
			dfs(v);
		}else {
			if (vis[v] != inc(vis[u])) ok = 0;
		}
	}
	for (auto v : gg[u]) {
		if (!vis[v]) {
			vis[v] = dec(vis[u]);
			dfs(v);
		}else {
			if (vis[v] != dec(vis[u])) ok = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	rep(i, 1, m+1) {
		cin >> u >> v;
		g[u].pb(v);
		gg[v].pb(u);
	} 
	rep(i, 1, n+1) if (!vis[i]) {
		ok = 1; tmp.clear(); vis[i] = 1;
		dfs(i);
		if (!ok) { ans += 1ll * sz(tmp) * sz(tmp);
		}else {
			rep(i, 1, 4) use[i] = 0;
			for (auto u : tmp) use[vis[u]]++;
			rep(i, 1, 4) ok &= use[i] > 0;
			if (ok) ans += use[1] * use[2] + use[2] * use[3] + use[3] * use[1];
			else {
				int t = 0;
				for (auto u : tmp) ans += sz(g[u]);
			}
		}
	}
	cout << ans << endl;
	return 0;	
}