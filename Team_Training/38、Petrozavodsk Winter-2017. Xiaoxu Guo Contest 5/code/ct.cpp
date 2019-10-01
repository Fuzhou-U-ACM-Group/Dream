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
typedef long long ll;
typedef pair<int, int> pii;
typedef double db;
typedef vector<int> vi;

const int N = 22;

ll C[N][N], b[N];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  rep(i, 0, N) C[i][0] = C[i][i] = 1;
  rep(i, 0, N) rep(j, 1, i) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  b[0] = b[1] = 1;
  rep(i, 2, N) {
    rep(j, 0, i) b[i] += C[i - 1][j] * b[j];
    dd(i), de(b[i]);
  }
  return 0;
}
