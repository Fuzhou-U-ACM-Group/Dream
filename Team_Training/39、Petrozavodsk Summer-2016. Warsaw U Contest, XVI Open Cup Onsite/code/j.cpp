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
#define pw(x) (1ll << (x))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef double db;
typedef vector<int> vi;

const int N = 2020;

struct P {
	ll x, y;
	P() {}
	P(ll x, ll y) : x(x), y(y) {}
	void read() { cin >> x >> y; }
	void print() { dd(x), de(y); }
	P operator + (const P &c) const {
		return P(x + c.x, y + c.y);
	}
	P operator - (const P &c) const {
		return P(x - c.x, y - c.y);
	}
	bool operator < (const P &c) const {
		if(x != c.x) return x < c.x;
		return y < c.y;
	}
	ll len2() {
		return x * x + y * y;
	}
};

int n;
ll A, B, ans;
P p[N], q[N];

ll det(P a, P b) {
	return a.x * b.y - a.y * b.x;
}
ll dot(P a, P b) {
	return a.x * b.x + a.y * b.y;
}

bool cmp(P a, P b) {
	int o = P(0, 0) < a, t = P(0, 0) < b;
	if(o != t) return o < t;
	ll k = det(a, b);
	if(k) return k > 0;
	return a.len2() < b.len2();
}
int calc(int l, int r, ll A, P p) {
	if(l == r) return 0;
	--r; int ans = l - 1;
	while(l <= r) {
		int mid = l + r >> 1;
		if(det(p, q[mid]) <= A) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	de(ans);
	return ans;
}
void solve(int s) {
	rep(i, 0, n) q[i] = p[i] - p[s];
	int m = n - 1;
	swap(q[n - 1], q[s]);
	sort(q, q + m, cmp);
	rep(i, 0, m) q[i].print();
	int l = 0, r = 0;
	rep(i, 0, m) {
		while(dot(q[i], q[l]) > 0) l = (l + 1) % m;
		de(l);
		while(dot(q[i], q[r]) > 0 || (dot(q[i], q[r]) == 0 && det(q[i], q[r]) > 0)) r = (r + 1) % m;
		// [l, r)
		dd(i), dd(l), de(r);
		ans += calc(l, r, 2 * B, q[i]) - calc(l, r, 2 * A - 1, q[i]);
	}
}

int main() {
//	std::ios::sync_with_stdio(0);
//	std::cin.tie(0);
	cin >> n >> A >> B;
	rep(i, 0, n) p[i].read();
	solve(0);
//	rep(i, 0, n) solve(i);
	cout << ans << endl;
	return 0;
}
