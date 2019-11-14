//#pragma GCC optimize(3)
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse2")
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) (a).begin(), (a).end()
#define pw(x) (1ll<<(x))
#define lb(x) ((x) & -(x))
#define endl "\n"
#define FI(x) freopen(#x".in","r",stdin)
#define FO(x) freopen(#x".out","w",stdout)
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
//typedef uniform_int_distribution<ll> RR;
//mt19937 gen(998244353);
//ll rnd(ll l, ll r) { RR dis(l, r); return dis(gen); }
const int P = 998244353;
int add(int a, int b) {if((a += b) >= P) a -= P; return a < 0 ? a + P : a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int M = 1 << 17 << 1;
int a[M], b[M];

struct NTT{
	static const int G = 3, P = 998244353; //P = C*2^k + 1
	int N, na, nb, w[2][M], rev[M];
	ll kpow(ll a, int b){
		ll c = 1;
		for (; b; b >>= 1,a = a * a % P) if (b & 1) c = c * a %P;
		return c;
	}
	void FFT(int *a, int f){
		rep(i, 0, N) if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int i = 1; i < N; i <<= 1)
			for (int j = 0, t = N / (i << 1); j < N; j += i << 1)
				for (int k = 0, l = 0, x, y; k < i; k++, l += t)
					x = (ll) w[f][l] * a[j+k+i] % P, y = a[j+k], a[j+k] = (y+x) % P, a[j+k+i] = (y-x+P) % P;
		if (f) for (int i = 0, x = kpow(N, P-2); i < N; i++) a[i] = (ll)a[i] * x % P;
	}
	void work(){
		int d = __builtin_ctz(N);
		w[0][0] = w[1][0] = 1;
		for (int i = 1, x = kpow(G, (P-1) / N), y = kpow(x, P-2); i < N; i++) {
			rev[i] = (rev[i>>1] >> 1) | ((i&1) << (d-1));
			w[0][i] = (ll)x * w[0][i-1] % P, w[1][i] = (ll) y * w[1][i-1] % P;
		}
	}
	void doit(int *a, int *b, int na, int nb){ // [0, na)
		for (N = 1; N < na + nb - 1; N <<= 1);
		rep(i, na, N) a[i] = 0;
		rep(i, nb, N) b[i] = 0;
		work(), FFT(a,0), FFT(b,0);
		rep(i, 0, N) a[i] = (ll)a[i] * b[i] % P;
		FFT(a, 1);
		//rep(i, 0, N) cout << a[i] << endl;
	}
} ntt;

int n, k, f[M], g[M], h[M], u[M];

void dfs(int d) {
	rep(i, 1, k+1) a[i] = k;
}

int main() {
	//FI(a);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	dfs(1);
	cin >> n >> k;
	rep(i, 1, n+1) f[i] = kpow(k, (i + 1) / 2);
	u[1] = 1;
	rep(i, 1, n+1)
		for (int j = i + i; j <= n; j += i) u[j] -= u[i];
	rep(i, 1, n+1)
		for (int j = i; j <= n; j += i) h[j] = add(h[j], mul(u[j / i], f[i]));
	rep(i, 1, n+1) a[i] = b[i] = f[i];
	ntt.doit(a, b, n+1, n+1);
	rep(i, 1, n+1) g[i] = add(a[i], f[i]);
	//rep(i, 1, n+1) de(h[i]);
	rep(i, 1, n+1) 
		for (int j = i; j <= n; j += i) g[j] = add(g[j], -mul(j / i - 1, h[i]));
	int ans = 0;
	de(g[n]);
	
	rep(i, 1, n+1) ans = add(ans, g[i]);
	cout << ans << endl;
	return 0;
}


