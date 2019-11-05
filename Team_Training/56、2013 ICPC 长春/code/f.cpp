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
#define pw(x) (1ll << (x))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef pair<int, int> pii;
typedef long double db;
typedef vector<int> vi;

const int N = 111;

db a[N][N];
db x[N], sx[N];

namespace GaussDB {
	static const int N = 505;
	int free[N], fnum, k, col, p;
	const db eps = 1e-14;

	void genx(int var) {
		int pre = var; fnum = 0;
		per(i, 0, k) {
			rep(j, 0, var) if(fabs(a[i][j]) > eps) { p = j; break; }
			rep(j, 0, i) if(fabs(a[j][p]) > eps) {
				db t = a[j][p] / a[i][p];
				rep(l, p, var + 1) a[j][l] -= a[i][l] * t;
			}
			rep(j, p + 1, pre) free[fnum++] = j; // x[j] = ?;
			pre = p;
			x[p] = a[i][var];
			rep(j, p + 1, var) x[p] -= a[i][j] * x[j];
			x[p] /= a[i][p];
		}
		rep(j, 0, pre) free[fnum++] = j;
	}
	int Gauss(int equ, int var) {
		for(k = col = 0; k < equ && col < var; ++k, ++col) {
			p = k; rep(i, k + 1, equ) if(fabs(a[i][col]) > fabs(a[p][col])) p = i;
			if(p != k) rep(j, col, var + 1) swap(a[p][j], a[k][j]);
			if(fabs(a[k][col]) < eps) { k--; continue; }
			rep(i, k + 1, equ) {
				if(fabs(a[i][col]) < eps) continue;
				db t = a[i][col] / a[k][col];
				rep(j, col, var + 1) a[i][j] -= a[k][j] * t;
			}
		}
		rep(i, k, equ) if(fabs(a[i][var]) > eps) return -1;
		if(k < var) {
			return var - k;
		}
		per(i, 0, var) {
			db t = a[i][var];
			rep(j, i + 1, var) if(fabs(a[i][j]) > eps) t -= x[j] * a[i][j];
			x[i] = t / a[i][i];
		}
		return 0;
	}
};

vi g[N], ng[N];
int n, m;
bool vis[N];
db y[N], tmp[N];
db px;

const db eps = 1e-8;

int sign(db x) {
	return (x > eps) - (x < -eps);
}


bool check1() {
	rep(i, 0, n) y[i] = sx[i];
	rep(t, 0, 10) {
		rep(i, 0, n) {
			db c = y[i] / sz(g[i]);
			for(auto j : g[i]) tmp[j] += c;
		}
		rep(j, 0, n) y[j] = tmp[j], tmp[j] = 0;
	}
	return sign(y[n - 1] - sx[n - 1]) > 0;
}

bool check() {
	rep(i, 0, n + 1) rep(j, 0, n + 1) a[i][j] = 0;
	rep(j, 0, n + 1) a[n][j] = 1;
	rep(i, 0, n) {
		for(auto j : ng[i]) a[i][j] = 1. / sz(g[j]);
		a[i][i] = -1;
	}
	int res = GaussDB::Gauss(n + 1, n);
	if(res == 0 && sign(x[n - 1] - px) > 0) return 1;
	return 0;
}

int work() {
	int res = -1;
	px = x[n - 1];
	rep(i, 0, n - 1) if(!vis[i]) {
		g[n - 1].pb(i);
		ng[i].pb(n - 1);
		if(check1() && check()) px = x[n - 1], res = i;
		g[n - 1].pop_back();
		ng[i].pop_back();
	}
	return res;
}

void solve() {
	cin >> n >> m;
	rep(i, 0, n) g[i].clear(), ng[i].clear(), vis[i] = 0;
	rep(i, 1, m + 1) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		ng[v].pb(u);
		if(u == n - 1) vis[v] = 1;
	}
	rep(i, 0, n + 1) rep(j, 0, n + 1) a[i][j] = 0;
	rep(j, 0, n + 1) a[n][j] = 1;
	rep(i, 0, n) {
		for(auto j : ng[i]) a[i][j] = 1. / sz(g[j]);
		a[i][i] = -1;
	}
	int res = GaussDB::Gauss(n + 1, n);
	rep(i, 0, n) sx[i] = x[i];
	if(res != 0) {
		cout << "INF" << endl;
		return ;
	}
	cout << 1 << " ";
	cout << work() << endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T; cin >> T;
	while(T--) solve();
	return 0;
}
