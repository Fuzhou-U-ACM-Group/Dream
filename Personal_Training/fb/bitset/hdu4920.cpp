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
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a < 0 ? a + P : a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 805;
int n, x;
bitset<805> t0, t1, t2, a[N][3], b[N][3];

int main() {
	FI(a);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	while (cin >> n) {
		rep(i, 0, n) rep(j, 0, 3) a[i][j].reset(), b[i][j].reset();
		rep(i, 0, n)
			rep(j, 0, n) {
				cin >> x;
				x %= 3;
				a[i][x].set(j);
			}
		rep(i, 0, n)
			rep(j, 0, n) {
				cin >> x;
				x %= 3;
				b[j][x].set(i);
			}
		rep(i, 0, n) rep(j, 0, n) {
			//t0 = a[i][0] | b[j][0];
			t1 = (a[i][1] & b[j][1]) | (a[i][2] & b[j][2]);
			t2 = (a[i][2] & b[j][1]) | (a[i][1] & b[j][2]);
			cout << (t1.count() + t2.count() * 2) % 3 << " \n"[j == n - 1];
		}
	} 
	return 0;
}


