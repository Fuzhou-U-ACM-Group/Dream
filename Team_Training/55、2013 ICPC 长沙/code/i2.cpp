#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pw(x) (1ll << (x))
typedef long long ll;
typedef pair<int, int> pii;
typedef double db;
typedef vector<int> vi;

const int N = 101010;

int n, x, y;
ll w[N], f[N], g[N], c[N], a[N];
vi h[N];

void dfs(int u) {
	ll sf = 0, sg = 0;
	for(auto v : h[u]) {
		dfs(v);
		sf += f[v], sg += g[v];
	}
	int i = u;
	f[i] = max(a[i] + sf, w[c[i]] - a[i] - sg);
	g[i] = max(a[i] + sg, w[c[i]] - a[i] - sf);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	while(cin >> n >> x >> y) {
		rep(i, 1, n + 1) h[i].clear();
		w[0] = x, w[1] = y;
		rep(i, 1, n + 1) {
			int fa; int t;
			cin >> a[i] >> fa >> t >> c[i];
			if(t) c[i] ^= 1;
			if(c[i]) a[i] = -a[i];
			h[fa].pb(i);
		}
		dfs(0);
		cout << f[0] << endl;
	}
	return 0;
}
