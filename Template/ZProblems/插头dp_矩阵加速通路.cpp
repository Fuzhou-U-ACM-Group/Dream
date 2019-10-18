/*
 * 给定 7 * 1e9 的棋盘，格子四联通，每个格子必走。求左上走到左下的方案数。
 */
const int P = 7777777, N = 150;
int n, m, id[20202], t[22], k, dp[2][N]; vi sta;
inline int add(int a, int b) {
  if((a += b) >= P) a -= P;
  return a;
}
inline int mul(int a, int b) { return 1ll * a * b % P; }
struct HM {
  static const int N = pw(16);
  int hd[N], s[N], L, f[N];
  inline void init() {
    rep(i, 0, L) hd[s[i]] = -1;
    L = 0;
  }
  inline void upd(int u, int v) {
    if(~hd[u]) {
      int i = hd[u];
      f[i] = add(f[i], v);
    } else {
      s[L] = u, f[L] = v; hd[u] = L++;
    }
  }
}hm[2];
struct Mat {
  ll a[N][N];
  Mat() { rep(i, 0, k) rep(j, 0, k) a[i][j] = 0; }
  void reset() { rep(i, 0, k) rep(j, 0, k) a[i][j] = 0; }
  void set() { rep(i, 0, k) a[i][i] = 1; }
  inline Mat operator * (const Mat &c) const {
    Mat r;
    rep(i, 0, k) rep(j, 0, k) rep(t, 0, k) r.a[i][j] += a[i][t] * c.a[t][j];
    rep(i, 0, k) rep(j, 0, k) r.a[i][j] %= P;
    return r;
  }
}A;
Mat kpow(Mat a, int b) {
  Mat r; r.set();
  while(b) {
    if(b & 1) r = r * a;
    a = a * a;
    b >>= 1;
  }
  return r;
}
void gao(int s) {
  int o = 0; hm[o].init(); hm[o].upd(sta[s] << t[1], 1);
  rep(j, 1, n + 1) {
    o ^= 1; hm[o].init();
    rep(k, 0, hm[o ^ 1].L) {
      int x = hm[o ^ 1].s[k], y = hm[o ^ 1].f[k];
      if(x >> t[n + 1]) continue;
      int p = x >> t[j - 1] & 3, q = x >> t[j] & 3;
      int tx = x ^ p << t[j - 1] ^ q << t[j];
      if(!p && !q) {
	hm[o].upd(x | (1 << t[j - 1]) | (2 << t[j]), y);
      } else if(!p || !q) {
	hm[o].upd(x, y);
	hm[o].upd(x ^ ((p | q) << t[j - 1]) ^ ((p | q) << t[j]), y);
      } else if(p == q) {
	int now = 0, nx = tx;
	for(int _ = p == 1 ? j + 1 : j - 2; ; p == 1 ? ++_ : --_) {
	  int c = x >> t[_] & 3;
	  if(!c) continue;
	  c == p ? ++now : --now;
	  if(now == -1) {
	    hm[o].upd(nx ^ (3 << t[_]), y);
	    break;
	  }
	}
      } else if(p == 2 && q == 1) {
	hm[o].upd(tx, y);
      }
    }
  }
  rep(_, 0, hm[o].L) if(!(hm[o].s[_] >> t[n])) {
    int i = id[hm[o].s[_]];
    A.a[i][s] = add(A.a[i][s], hm[o].f[_]);
  }
}
bool check(int x) {
  int now = 0;
  rep(i, 0, n) {
    int c = x >> t[i] & 3;
    if(c == 3) return 0;
    if(c == 1) ++now;
    if(c == 2) --now;
    if(now < 0) return 0;
  }
  return now == 0;
}
int solve() {
  if((n & 1) && !(m & 1)) return 0;
  sta.clear();
  rep(i, 0, pw(n << 1)) if(check(i)) {
    id[i] = sz(sta);
    sta.pb(i);
  }
  k = sz(sta); A.reset();
  rep(j, 0, k) gao(j);
  A = kpow(A, m);
  int i = id[1 ^ 2 << t[n - 1]];
  return A.a[i][0];
}
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  rep(i, 0, 22) t[i] = i + i;
  memset(hm[0].hd, -1, sizeof(hm[0].hd));
  memset(hm[1].hd, -1, sizeof(hm[0].hd));
  while(cin >> n >> m) {
    int ans = solve();
    if(ans) cout << ans << endl;
    else cout << "Impossible" << endl;
  }
  return 0;
}