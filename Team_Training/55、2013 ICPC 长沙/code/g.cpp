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
typedef pair<int, int> pii;
typedef double db;
typedef vector<int> vi;

const int N = 105;
vector<pii> ans, tmp, ans1;
int n, du[N], a[N][N], b[N][N], c[N][N], vis[N];
vector<pii> solve(vector<pii> tmp, int o) {
	vector<pii> ans;
	while (sz(tmp)) {
		sort(all(tmp));
		if (sz(tmp) - 1 < tmp.back().fi) {
			ans.clear();
			ans.pb(mp(-1, -1));
			return ans;
		}
		per(i, 0, sz(tmp) - 1) {
			tmp[i].fi--;
			tmp.back().fi--;
			if (o) ans.pb(mp(tmp.back().se * -1, tmp[i].se * -1)); 
			else ans.pb(mp(tmp.back().se, tmp[i].se));

			if (tmp.back().fi == 0) break;
		}
		vector<pii> tt;
		rep(i, 0, sz(tmp)) if (tmp[i].fi > 0) tt.pb(tmp[i]);
		tmp = tt;
	}
	return ans;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	while (cin >> n) {
		rep(i, 1, n+1) cin >> du[i];
		
		tmp.clear();
		rep(i, 1, n+1) {
			if (du[i]) tmp.pb(mp(du[i], i));
		}
		ans = solve(tmp, 0);
		if (sz(ans) && ans[0].fi == -1) { cout << "IMPOSSIBLE" << endl; continue;}
		rep(i, 1, n+1) rep(j, 1, n+1) a[i][j] = 0;
		for (auto v : ans) a[v.fi][v.se] = a[v.se][v.fi] = 1;  
		rep(i, 1, n+1) rep(j, 1, n+1) c[i][j] = a[i][j];
		bool oo = 0;
		for (auto v : ans) {
			rep(i, 1, n+1) vis[i] = 0;
			vis[v.fi] = 1;
			vis[v.se] = 1;
			rep(j, 1, n+1) if (a[v.fi][j]) vis[j] = 1;
			vi tt;
			rep(i, 1, n+1) if (!vis[i]) tt.pb(i);
				rep(i, 0, sz(tt)) {
					rep(j, 1, n+1) if (j != v.fi && j != v.se && a[tt[i]][j]){
						oo = 1;
						c[v.fi][v.se] = c[v.se][v.fi] = 0;
						c[tt[i]][j] = c[j][tt[i]] = 0;
						c[v.fi][tt[i]] = c[tt[i]][v.fi] = 1;
						c[v.se][j] = c[j][v.se] = 1;
						break;
					}
					if (oo) break;
				}
			
			if (oo) break;
		}



		
		tmp.clear();
		rep(i, 1, n+1) {
			if (du[i]) tmp.pb(mp(du[i], -i));
		}
		ans1 = solve(tmp, 1);
		rep(i, 1, n+1) rep(j, 1, n+1) b[i][j] = 0;
		for (auto v : ans1) b[v.fi][v.se] = b[v.se][v.fi] = 1;  	
		bool ok = 1;
		rep(i, 1, n+1) rep(j, 1, n+1) if (a[i][j] != b[i][j]) { ok = 0; break; }


		if (!ok) {
			cout << "MULTIPLE" << endl;
			cout << n << " " << sz(ans) << endl;
			rep(i, 0, sz(ans)) cout << ans[i].fi << " \n"[i == sz(ans) - 1];
			rep(i, 0, sz(ans)) cout << ans[i].se << " \n"[i == sz(ans) - 1];
			cout << n << " " << sz(ans) << endl;
			if (oo) {
				ans1.clear();
				rep(i, 1, n+1) rep(j, i+1, n+1) if (c[i][j]) ans1.pb(mp(i, j));
			}
			rep(i, 0, sz(ans1)) cout << ans1[i].fi << " \n"[i == sz(ans1) - 1];
			rep(i, 0, sz(ans1)) cout << ans1[i].se << " \n"[i == sz(ans1) - 1];
		}else { 
			cout << "UNIQUE" << endl;
			cout << n << " " << sz(ans) << endl;
			if (sz(ans) == 0) cout << endl << endl;
			rep(i, 0, sz(ans)) cout << ans[i].fi << " \n"[i == sz(ans) - 1];
			rep(i, 0, sz(ans)) cout << ans[i].se << " \n"[i == sz(ans) - 1];
		}
	}
	return 0;
}
