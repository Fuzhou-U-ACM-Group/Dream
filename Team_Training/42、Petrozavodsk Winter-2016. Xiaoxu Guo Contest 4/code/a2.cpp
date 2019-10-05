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
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 202020;

int n, fail[N], rt;
vi vec[N];

void ini() { fail[0] = N - 1; }

struct Ht {
	static const int N = 23333333;
	int L, hd[N], ne[N], pp[N], cc[N], val[N];
	inline void init() {
		memset(hd, -1, sizeof(hd));
	}
	inline int id(int p, int c) {
		return (p * 1ll * ::N + c) % N;
	}
	inline int qry(int p, int c) {
		int k = id(p, c);
		for(int i = hd[k]; ~i; i = ne[i]) {
			if(pp[i] == p && cc[i] == c) return val[i];
		}
		return -1;
	}
	inline void add(int p, int c, int w) {
		bool f = 0;
		int k = id(p, c);
		for(int i = hd[k]; ~i; i = ne[i]) {
			if(pp[i] == p && cc[i] == c) {
				f = 1;
				val[i] = w;
				break;
			} 
		}
		if(!f) {
			pp[L] = p, cc[L] = c, val[L] = w;
			ne[L] = hd[k], hd[k] = L;
			L++;
			vec[p].pb(c);
		}
	}
} ht;

int calc(int p, int c) {
	while(p != N - 1 && ht.qry(p, c) == -1) p = fail[p];
	return max(0, ht.qry(p, c));
}
void build() {
	vi v; v.pb(rt);
	rep(i, 0, sz(v)) {
		int p = v[i];
		for(auto c : vec[p]) {
			int k = ht.id(p, c);
			for(int i = ht.hd[k]; ~i; i = ht.ne[i]) {
				int pp = ht.pp[i], cc = ht.cc[i];
				if(p == pp && c == cc) {
					int val = ht.val[i];
					v.pb(val), fail[val] = calc(fail[p], c);
				}
			}
		}
	}
}
int p[N], c[N];
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n + 1) cin >> p[i];
	rep(i, 1, n + 1) cin >> c[i];
	ht.init();
	rep(i, 1, n + 1) ht.add(p[i], c[i], i);
	ini();
	build();
	rep(i, 1, n + 1) cout << fail[i] << " \n"[i == n];
	return 0;
}
