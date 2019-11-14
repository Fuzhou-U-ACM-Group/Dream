/*
 * 给定 9 * 9 的棋盘，格子四联通，有两类格子， 1 不能走 0 可以走。要求从 S1 走到 T1 ，从 S2 走到 T2 ，且路径不相交，求最短路径。
 */
int n, m, a[22][22], t[22];
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
      f[i] = min(f[i], v);
      return ;
    }
    s[L] = u; f[L] = v; ne[L] = hd[p]; hd[p] = L++;
  }
}hm[2];
int solve() {
  int o = 0; hm[o].init(); hm[o].upd(0, 0);
  rep(i, 1, n + 1) {
    rep(k, 0, hm[o].L) {
      if(hm[o].s[k] >> t[m]) hm[o].f[k] = -1;
      else hm[o].s[k] <<= 3;
    }
    rep(j, 1, m + 1) {
      o ^= 1; hm[o].init();
      rep(k, 0, hm[o ^ 1].L) {
	int x = hm[o ^ 1].s[k], y = hm[o ^ 1].f[k] + 1;
	if(x >> t[m + 1] || y <= 0) continue;
	int p = x >> t[j - 1] & 7, q = x >> t[j] & 7;
	int tx = x ^ (p << t[j - 1]) ^ (q << t[j]);
	if(a[i][j] == 1) {
	  if(!p && !q) hm[o].upd(x, y - 1);
	} else if(a[i][j] == 0) {
	  if(!p && !q) {
	    hm[o].upd(x | (1 << t[j - 1]) | (2 << t[j]), y);
	    hm[o].upd(x, y - 1);
	  } else if(!p || !q) {
	    int k = max(p, q);
	    hm[o].upd(x, y);
	    hm[o].upd(x ^ (k << t[j - 1]) ^ (k << t[j]), y);
	  } else if(p == 1 && q == 2) {
	  } else if(p == 2 && q == 1 || p == q && p >= 3) {
	    hm[o].upd(tx, y);
	  } else if(min(p, q) <= 2) {
	    int mi = min(p, q), now = 1, nx = tx;
	    for(int _ = mi == 1 ? j + 1 : j - 2; ; mi == 1 ? ++_ : --_) {
	      int c = x >> t[_] & 7;
	      if(c == mi) ++now;
	      if(c == (mi ^ 3)) --now;
	      if(!now) {
		hm[o].upd(nx ^ ((3 ^ p ^ q) << t[_]), y);
		break;
	      }
	    }
	  }
	} else {
	  int kk = a[i][j] + 1;
	  if(!p && !q) {
	    hm[o].upd(x | (kk << t[j - 1]), y);
	    hm[o].upd(x | (kk << t[j]), y);
	  } else if(!p || !q) {
	    int ma = max(p, q);
	    if(ma == kk) {
	      hm[o].upd(tx, y);
	    } else if(ma <= 2) {
	      int now = 1, nx = tx;
	      for(int _ = ma == 1 ? j + 1 : j - 2; ; ma == 1 ? ++_ : --_) {
	      	int c = x >> t[_] & 7;
	      	if(c == ma) ++now;
	      	if(c == (ma ^ 3)) --now;
	      	if(!now) {
	      	  hm[o].upd(nx ^ ((3 ^ ma ^ kk) << t[_]), y);
	      	  break;
		}
	      }
	    }
	  }
	}
      }
    }
  }
  int ans = 0;
  rep(i, 0, hm[o].L) if(!hm[o].s[i]) ans = hm[o].f[i] - 2;
  return ans;
}
int main() {
  rep(i, 0, 22) t[i] = i + i + i;
  while(cin >> n >> m) {
    if(!n && !m) break;
    rep(i, 1, n + 1) rep(j, 1, m + 1) cin >> a[i][j];
    cout << solve() << endl;
  }
  return 0;
}