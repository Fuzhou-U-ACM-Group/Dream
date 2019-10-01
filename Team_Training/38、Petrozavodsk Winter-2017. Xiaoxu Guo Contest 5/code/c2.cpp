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
#define endl "\n"
#define pw(x) (1ll << (x))
#define all(a) a.begin(), a.end()
#define sz(x) (int)x.size()
#define cnt(i) vec[i][0]
typedef long long ll;
typedef pair<ll, ll> pii;
typedef double db;
typedef vector<int> vi;

const int N = 55, M = 1e7;

int n, m;
vi g[N];
pii vec[N][M];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  cin >> n >> m;
  rep(i, 1, m + 1) {
    int u, v; cin >> u >> v; if(u > v) swap(u, v);
    g[v].pb(u);
  }
  // f[0][AAA..A][1] = 0
  vec[0][++cnt(0)] = mp(1, 0); 
  rep(i, 1, n + 1) {
    rep(j, 1, cnt(i - 1) + 1) {
      ll t = vec[i][j].se;
      if(!t) continue;
      ll a = vec[i][j].fi, b = a % 100; a /= 100;
      // del
      if(b) {
      } else {
      }
      // add
    }
  }
  return 0;
}
