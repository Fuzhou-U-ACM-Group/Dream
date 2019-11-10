namespace DAG {
	const int N = ::N, M = 18, lim = 1e9;
	bool sp[N]; ll dp[N]; // init
	int ne[M][N]; ll cnt[M][N]; vector<ll> pre[N];

	void build(vector<pii> g[]) {
		rep(i, 1, n + 1) {
			ne[0][i] = 0; ll md = -1; int col = 0;
			for(auto j : g[i]) if(dp[j.se] > md) md = dp[j.se], ne[0][i] = j.se, col = j.fi;
			cnt[0][i] = sp[i]; pre[i] = vector<ll>(sz(g[i]));
			rep(j, 0, sz(pre[i])) {
				pii t = g[i][j];
				pre[i][j] = (j == 0 ? sp[i] : pre[i][j - 1]) + dp[t.se];
				if(t.fi < col) cnt[0][i] = min((ll)lim, cnt[0][i] + dp[t.se]);
			}
		}
		rep(i, 1, M) rep(j, 1, n + 1) {
			int t = ne[i - 1][j];
			ne[i][j] = ne[i - 1][t];
			cnt[i][j] = min((ll)lim, cnt[i - 1][j] + cnt[i - 1][t]);
		}
	}
	int qry(int k) {
		int ans = 0, u = 1;
		while(1) {
			per(i, 0, M) if(ne[i][u] && cnt[i][u] < k && k <= cnt[i][u] + dp[ne[i][u]]) {
				ans += pw(i);
				k -= cnt[i][u];
				u = ne[i][u];
			}
			if(k == 1 && sp[u]) break;
			int p = lower_bound(all(pre[u]), k) - pre[u].begin();
			k -= (p == 0 ? sp[u] : pre[u][p - 1]);
			u = g[u][p].se;
			++ans;
		}
		return ans;
	}
}
