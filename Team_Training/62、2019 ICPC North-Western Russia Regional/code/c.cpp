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

const int N = 111;

int n, m, ct;
char s[N][N];
vector<pii> ans;

void solve() {
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 0, n) {
		cin >> s[i];
		rep(j, 0, m) if(s[i][j] == 'X') ++ct;
	}
	solve();
	assert(sz(ans) == ct * 4 - 1);
	cout << sz(ans) - 1 << endl;
	for(auto u : ans) cout << u.fi << " " << u.se << endl;
	return 0;
}
