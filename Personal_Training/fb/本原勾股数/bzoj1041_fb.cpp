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

vector<vi> ans;

int n, m;

int get(int n) {
	int res = 0;
	m = sqrt(n);
	rep(i, 1, m+1) if (n % i == 0){
		int t = i * 2;
		for (int j = 3; j * j < t; j += 2) if (2ll * j * j > t) {
			int k = sqrt(t - j * j);
			if (k * k + j * j == t && (k & 1) && __gcd(k, j) == 1) res += 2;
		}
		t = n / i * 2;
		if (i * i != n) {
			for (int j = 3; j * j < t; j += 2) if (2ll * j * j > t) {
				int k = sqrt(t - j * j);
				if (k * k + j * j == t && (k & 1) && __gcd(k, j) == 1) res += 2;
			}
		}
	}
	return res * 4 + 4;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	cout << get(n) << endl;
	return 0;
}


