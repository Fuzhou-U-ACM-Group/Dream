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
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 222;

int n, m, ct;
char s[N][N];
vector<pii> ans;
bool vis[N * N * 10];
vector<pii> g[N * N * 10];
int p[N * N * 10];
int L;
bool check(int o, int t) {
	if(o > 0 && t < 0) return 1;
	if(o < 0 && t > 0) return 1;
	return 0;
}
pii Get(int u) {
	return mp(u / (m + 3), u % (m + 3));
}
void dfs(int u, int o) {
	for( ; p[u] < sz(g[u]); ++p[u]) {
		auto v = g[u][p[u]];
		if(vis[abs(v.se)] || check(o, v.se)) continue;
		vis[abs(v.se)] = 1;
		dfs(v.fi, o * -1);
		ans.pb(Get(v.fi));
	}
}

int id(int i, int j) {
	return i * (m + 3) + j;
}
void solve() {
	rep(i, 0, n) rep(j, 0, m) if(s[i][j] == 'X') {
		dfs(id(i, j), 1), ans.pb(mp(i, j));
		break;
	}
}


void add(int u, int v, int o) {
	++L;
	g[u].pb(mp(v, o * L));
	g[v].pb(mp(u, o * L));
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> m >> n;
	rep(i, 0, n) {
		cin >> s[i];
		rep(j, 0, m) {
			if(s[i][j] == 'X') {
				++ct;
				add(id(i, j), id(i + 1, j + 1), 1);
				add(id(i + 1, j), id(i, j + 1), 1);
			}
		}
	}
	rep(i, 0, n + 1) rep(j, 0, m + 1) {
		add(id(i, j), id(i + 1, j), -1);
		add(id(i, j), id(i, j + 1), -1);
	}
	solve();
	reverse(all(ans));
	//	assert(sz(ans) == ct * 4 - 1);
	cout << sz(ans) - 1 << endl;
	for(auto u : ans) cout << u.se << " " << u.fi << endl;
	return 0;
}
