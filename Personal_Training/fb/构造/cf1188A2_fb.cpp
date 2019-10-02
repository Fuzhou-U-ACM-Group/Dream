#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) (a).begin(), (a).end()
#define pw(x) (1ll<<(x))
#define lb(x) ((x) & -(x))
#define endl "\n"
#define FI(x) freopen(#x".in","r",stdin)
#define FO(x) freopen(#x".out","w",stdout)
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
//typedef uniform_int_distribution<ll> RR;
//mt19937 gen(998244353);
//ll rnd(ll l, ll r) { RR dis(l, r); return dis(gen); }
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a < 0 ? a + P : a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

void dfs(int u) {
	vis[u] = 1;
	for (auto v : g[u]) if (!vis[v.fi]) dfs(v.fi);
}

int reduce(int u) {
	rep(i, 1, n+1) vis[i] = 0, du[i] = 0;
	dfs(u, 0);
	rep(i, 1, n+1) if (vis[i]) for (auto u : g[i]) du[u.fi]++;
	queue<int> q;
	rep(i, 1, n+1) if (vis[i] && du[i] == 2) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop(); vis[u] = 0;
		if (g[u][0].se != g[u][1].se) return -1;
		int x = g[u][0].fi, y = g[u][1].fi;
		for (auto v : g[x]) if (v.fi == u) {v.fi = y; break;}
		for (auto v : g[y]) if (v.fi == u) {v.fi = x; break;}
	}
	rep(i, 1, n+1) if (vis[i] && du[i] > 1) return i;
	rep(i, 1, n+1) if (vis[i]) return i;
}

void get(int u, vi &t, int fa) {
	bool ok = 1;
	for (auto v : g[u]) if (v.fi != fa) {
		get(v.fi, t, u);
		ok = 0;
		if (sz(t) == 2) return;
	}
	if (!ok) t.pb(u);
}

void solve(int rt) {
	if (rt == -1) {
		cout << "NO" << endl;
		exit(0);
	}
	if (du[rt] == 0) return;
	if (du[rt] == 1) {
		ans.pb(mp(mp(rt, g[rt][0].fi), g[rt][0].se));
		return;
	}
	for (auto v : g[rt]) {
		vi now, t1, t2, t3;
		for (auto vv : g[rt]) if (vv.fi != v.fi) {
			now.pb(vv.fi);
			if (sz(now) == 2) break;
		}
		get(now[0], t1, rt);
		get(now[1], t2, rt);
		get(v.fi, t3, rt);
		ans.pb(mp(mp(t3[0], t3[1]), -x / 2))
	}
}

int main() {
	//FI(a);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n) {
		cin >> u >> v >> w;
		g[u].pb(mp(v, w));
		g[v].pb(mp(u, w));
	}
	rt = reduce(1);
	solve(rt);
	return 0;
}


