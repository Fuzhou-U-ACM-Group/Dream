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

const int N = 2020;

vector<pii> g[N];
int n, m, k, u, v, w;
bool vis[N][N];
ll ans;
struct Data {
	int w; int st, last, id;
	Data(int w, int st, int last, int id) : w(w), st(st), last(last), id(id) {}
	bool operator < (const Data &c) const {
		return w > c.w;
	}
};

void solve(int n, vector<pii> g[], int k) {
	priority_queue<Data> pq;
	rep(i, 1, n + 1) {
		if(sz(g[i])) pq.push(Data(g[i][0].fi, i, i, 0));
		vis[i][i] = 1;
	}
	while(!pq.empty()) {
		Data u = pq.top(); pq.pop();
		int v = g[u.last][u.id].se;
		if(!vis[u.st][v]) {
			vis[u.st][v] = 1;
			k--; ans += u.w * u.w;  if(k == 0) return;
			if(sz(g[v]) && u.w + g[v][0].fi <= n) pq.push(Data(u.w + g[v][0].fi, u.st, v, 0));
		} 
		if(u.id + 1 < sz(g[u.last])) {
			int w = u.w - g[u.last][u.id].fi + g[u.last][u.id + 1].fi;
			if(w <= n) pq.push(Data(u.w - g[u.last][u.id].fi + g[u.last][u.id + 1].fi, u.st, u.last, u.id + 1));
		}
	}
}
string s;
int cnt, cnt2, tmp[N], tmp2[N], x;
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) {
		cnt = cnt2 = 0;
		cin >> s;
		rep(j, 0, n) {
			if (s[j] == '1') tmp[cnt++] = j+1;else tmp2[cnt2++] = j+1;
		}
		g[i].resize(n);
		rep(j, 0, cnt) g[i][j] = mp(1, tmp[j]);
		rep(j, 0, cnt2) g[i][j+cnt] = mp(n, tmp2[j]);
	}
	solve(n, g, n * n - n);
	cout << ans << endl;
	return 0;
}
