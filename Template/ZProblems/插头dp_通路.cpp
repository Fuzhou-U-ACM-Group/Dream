/*
 * 给定 7 * 7 的棋盘，格子四联通，格子有收益或不能走。求通路的最大收益。
 */
int n, m, t[22], a[22][22];
struct HM {
  static const int INF = pw(18) - 1, N = 8e5;
  int hd[INF + 1], ne[N], s[N], L, f[N];
  void init() {
    memset(hd, -1, sizeof(hd));
    L = 0;
  }
  void upd(int u, int v) {
    int p = u & INF;
    for(int i = hd[p]; ~i; i = ne[i]) if(u == s[i]) {
      f[i] = max(f[i], v);
      return ;
    }
    s[L] = u; f[L] = v; ne[L] = hd[p]; hd[p] = L++;
  }
}hm[2];
int solve() {
  int ans = -INT_MAX;
  cin >> n >> m;
  rep(i, 1, n + 1) rep(j, 1, m + 1) {
    cin >> a[i][j]; 
    ans = max(ans, a[i][j]);
  }
  int o = 0; hm[o].init(); hm[o].upd(0, 0);
  rep(i, 1, n + 1) {
    rep(j, 0, hm[o].L) hm[o].s[j] <<= t[1];
    rep(j, 1, m + 1) {
      o ^= 1; hm[o].init();
      rep(k, 0, hm[o ^ 1].L) {
	int x = hm[o ^ 1].s[k], y = hm[o ^ 1].f[k] + a[i][j];
	if(x >> t[m + 1]) continue;
	int p = x >> t[j - 1] & 3, q = x >> t[j] & 3;
	int tx = x ^ (p << t[j - 1]) ^ (q << t[j]);
	if(a[i][j] == 0) {
	  if(!p && !q) hm[o].upd(x, y - a[i][j]);
	} else {
	  if(!p && !q) {
	    hm[o].upd(x | (1 << t[j - 1]) | (2 << t[j]), y);
	    hm[o].upd(x | (3 << t[j - 1]), y);
	    hm[o].upd(x | (3 << t[j]), y);
	    hm[o].upd(x, y - a[i][j]);
	  } else if(!p || !q) {
	    int k = max(p, q);
	    hm[o].upd(x, y);
	    hm[o].upd(x ^ (k << t[j - 1]) ^ (k << t[j]), y);
	    if(k == 3) {
	      if(!tx) ans = max(ans, y);
	    } else {
	      int now = 1, nx = tx;
	      for(int _ = k == 1 ? j + 1 : j - 2; ; k == 1 ? ++_ : --_) {
	      	int c = x >> t[_] & 3;
	      	if(c == k) ++now;
	      	if(c == (k ^ 3)) --now;
	      	if(!now) {
	      	  hm[o].upd(nx ^ (k << t[_]), y);
	      	  break;
		}
	      }
	    }
	  } else if(p == 1 && q == 2) {
	  } else if(p == 2 && q == 1) {
	    hm[o].upd(tx, y);
	  } else if(min(p, q) <= 2) {
	    int k = min(p, q), now = 1, nx = tx;
	    for(int _ = k == 1 ? j + 1 : j - 2; ; k == 1 ? ++_ : --_) {
	      int c = x >> t[_] & 3;
	      if(c == k) ++now;
	      if(c == (k ^ 3)) --now;
	      if(!now) {
		hm[o].upd(nx ^ ((3 ^ p ^ q) << t[_]), y);
		break;
	      }
	    }
	  } else {
	    if(!tx) ans = max(ans, y);
	  }
	}
      }
    }
  }
  return ans;
}
int main() {
  rep(i, 0, 22) t[i] = i + i;
  int T; cin >> T;
  while(T--) cout << solve() << endl;
  return 0;
}