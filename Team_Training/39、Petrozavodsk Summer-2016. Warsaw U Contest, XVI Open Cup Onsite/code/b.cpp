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
#define pw(x) (1ll << (x))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef double db;
typedef vector<int> vi;

const int N = 202020;

int n, m, k, a[N], b[N], pe[N], pre[N];
bool in[N];
int pos, col[N];
bool used[N];
pii e[N];
vi g[N];
set<int> st[N], del[N];
int tim;
int vis[N];
vi vec, vv;

int find(int x) {
	return x == pre[x] ? x : pre[x];
}
int calc(int u) {
	++tim;
	for(auto c : del[u]) vis[c] = tim;
	for(auto c : vv) if(vis[c] != tim) return c;
	return -1;
}
bool solve() {
	queue<int> que;
	rep(i, 1, n + 1) if(sz(st[i]) == 1) que.push(i), in[i] = 1;
	int pp = 0;
	pos = 1;
	rep(i, 1, sz(vec) + 1) {
		if(que.empty()) {
			while(col[vec[pp]]) ++pp;
			que.push(vec[pp]);
		}
		int u = que.front(); que.pop();
		//assert(sz(st[u]));
		int tt = (sz(st[u]) ? *st[u].begin() : calc(u));
		int c = col[u] = tt;
		if(c == -1) return 0;
		for(auto v : g[u]) {
			auto p = st[v].find(c);
			if(p != st[v].end()) st[v].erase(p);
			if(sz(st[u]) == 0) del[v].insert(c);
			if(sz(st[v]) <= 1 && !in[v]) que.push(v), in[v] = 1;
		}
	}
	return 1;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, m + 1) cin >> e[i].fi >> e[i].se;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n + 1) cin >> b[i];
	rep(i, 1, n + 1) pre[i] = i;
	rep(i, 1, n + 1) {
		int x = b[i];
		if(pe[x]) {
			pre[i] = pe[x];
		} else {
			pe[x] = i;
			vec.pb(i);
		}
	}
	pos = 0;
	rep(i, 1, n + 1) used[a[i]] = 1;
	rep(i, 1, k + 1) if(!used[i]) vv.pb(i);
	rep(i, 1, m + 1) {
		int u = e[i].fi, v = e[i].se;
		u = find(u), v = find(v);
		if(u != v) g[u].pb(v), g[v].pb(u);
	}
	rep(i, 1, n + 1) st[find(i)].insert(a[i]);
	if(solve()) {
		cout << "TAK" << endl;
		rep(i, 1, n + 1) cout << col[find(i)] << " \n"[i == n];
	} else {
		cout << "NIE" << endl;
	}
	return 0;
}
