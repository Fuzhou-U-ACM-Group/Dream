const int N = 34000;
int mu[N], p[N], tot = 0, Sqr, n;
bool vis[N];
int w1[N * 2], w2[N * 2], id1[N * 2], id2[N * 2], t1;// зЂвт longlong

void init(){
    mu[1] = 1;
    rep(i, 2, N) {
        if (!vis[i]) p[++tot] = i,mu[i]=-1; 
        for(int j = 1; j <= tot && p[j] * i < N; j++){
            int u = p[j] * i;
            vis[u] = 1;
            if(i % p[j] == 0) { mu[u] = 0; break; }
            mu[u] = -mu[i];
        }
    }
}

int id(int x) { return x <= Sqr ? id1[x] : id2[n / x];}

ll h1(int n){
    ll ans = 0;
    for(int l = 1, r; l<=n; l = r + 1){
        r = n / (n / l);
        ans += 1ll * (n / l) * (w1[id(r)] - w1[id(l-1)]);
    }
    return ans;
}

ll h2(int n){
    ll ans = 0;
    for(int l = 1, r; l <= n; l = r + 1){
        r = n / (n / l);
        ans += 1ll * (n / l) * (w2[id(r)] - w2[id(l-1)]);
    }
    return ans;
}

ll solve(int _n) {
	n = _n;
	Sqr = sqrt(n); t1 = 0;
    for(int l = 1, r; l <= n; l = r + 1){
        r = n / (n / l);
        int cnt1 = 0, cnt2 = 0;
        for(int i = 1; i * i < r; i++) cnt1 += sqrt(r - i * i);
        for(int i = 1; i * i < r; i += 2) cnt2 += (sqrt(r - i * i) + 1) / 2;
        w1[++t1] = cnt1, w2[t1] = cnt2;
        r <= Sqr ? id1[r] = t1 : id2[n / r] = t1;
    }
    ll ans = 0;
    for(int k = 1; k * k <= n; k++){
        if (mu[k] == 0) continue;
        ans += h1(n/k/k) * mu[k];
        if (k & 1) ans -= h2(n/k/k) * mu[k];
    }
    return ans / 2;
}

int T, nn;

int main() {
	FI(a);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	init();
	cin >> T;
	rep(cas, 0, T) {
		cin >> nn;
		cout << solve(nn) << endl;
	} 
	return 0;
}


