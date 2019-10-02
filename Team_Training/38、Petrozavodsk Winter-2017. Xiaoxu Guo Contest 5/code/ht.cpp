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

const int N = 222;

int a[N];

bool check(int n) {
  rep(i, 1, n + 1) a[i + n] = a[n + 1 - i];
  int m = n << 1;
  rep(i, 1, m + 1) rep(j, i + 1, m + 1) rep(k, j + 1, m + 1) rep(l, k + 1, m + 1) {
    if(a[i] < a[k] && a[k] < a[l] && a[l] < a[j]) return 0;
  }
  return 1;
}

int gao(int n) {
  if(n == 1) return 1;
  rep(i, 1, n + 1) a[i] = i;
  int ans = 0;
  do {
    ans += check(n);
    if (check(n)) rep(i, 1, n+1) cout << a[i] << " \n"[i == n];
  } while(next_permutation(a + 1, a + 1 + n));
  return ans;
}

int main() {
//  std::ios::sync_with_stdio(0);
 // std::cin.tie(0);
  rep(n, 1, 6) de(n), de(gao(n));
  return 0;
}
