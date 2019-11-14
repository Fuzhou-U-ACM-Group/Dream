/* 
 * 给定 12 * 12 的棋盘，格子四联通，有三类格子， X 不能走 O 必走 * 可走可不走。画一条回路，求方案数。
 */
int n, m, edx, edy, t[22], ok[22][22];
char s[22][22];
struct HM {
  static const int INF = pw(18) - 1, N = 8e5;
  int hd[INF + 1], ne[N], s[N], L; ll f[N];
  void init() {
    memset(hd, -1, sizeof(hd));
    L = 0;
  }
  void upd(int u, ll v) {
    int p = u & INF;
    for(int i = hd[p]; ~i; i = ne[i]) if(u == s[i]) {
      f[i] += v;
      return ;
    }
    s[L] = u; f[L] = v; ne[L] = hd[p]; hd[p] = L++;
  }
}hm[2];
void gao() {
  per(i, 1, n + 1) per(j, 1, m + 1) {
    ok[i][j] = 1;
    if(s[i][j] == 'O') return ;
  }
}
ll solve() {
  cin >> n >> m;
  rep(i, 1, n + 1) cin >> (s[i] + 1);
  rep(i, 1, n + 1) rep(j, 1, m + 1) ok[i][j] = 0;
  gao();
  ll ans = 0;
  int o = 0; hm[o].init(); hm[o].upd(0, 1);
  rep(i, 1, n + 1) {
    rep(j, 0, hm[o].L) hm[o].s[j] <<= t[1];
    rep(j, 1, m + 1) {
      o ^= 1; hm[o].init();
      rep(k, 0, hm[o ^ 1].L) {
	int x = hm[o ^ 1].s[k];
	if(x >> t[m + 1]) continue;
	int p = x >> t[j - 1] & 3, q = x >> t[j] & 3;
	int tx = x ^ (p << t[j - 1]) ^ (q << t[j]);
	ll y = hm[o ^ 1].f[k];
	if(s[i][j] == 'X') {
	  if(!p && !q) hm[o].upd(x, y);
	} else {
	  if(!p && !q) {
	    hm[o].upd(x | (1 << t[j - 1]) | (2 << t[j]), y);
	    if(s[i][j] == '*') hm[o].upd(x, y);
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
	  } else if(p == 1 && q == 2) {
	    if(ok[i][j] && !tx) ans += y;
	  } else if(p == 2 && q == 1) {
	    hm[o].upd(tx, y);
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
  rep(i, 1, T + 1) cout << "Case " << i << ": " << solve() << endl;
  return 0;
}
