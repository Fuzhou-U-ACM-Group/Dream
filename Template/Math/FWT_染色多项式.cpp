template<class T>
struct Poly{
	static const int N = 30, P = 1e9 + 7;
	T a1[N], b1[N], c[N];
	T add(T a, T b) {a = (a + b) % P; return a < 0 ? a + P : a;}
	T mul(T a, T b) {a = 1ll * a * b % P; return a < 0 ? a + P : a;}
	T kpow(T a, T b) {T r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
	void calc(int n, T *a, T *b) {
		fill_n(c, n+1, 0);
		rep(i, 0, n+1)	rep(j, 0, 2) c[i+j] = add(c[i+j], mul(a[i], b[j]));
		memcpy(a, c, sizeof(a[0]) * (n+1));
	} 
	void solve(int n, T *x, T *y, T *a){ // a[0]*x^0 ... a[n]*x^n
		fill_n(a, n+1, 0);
		rep(i, 0, n+1) {
			fill_n(a1, n+1, 0); a1[0] = 1;
			rep(j, 0, n+1) if (j != i) a1[0] = mul(a1[0], x[i] - x[j]);
			a1[0] = mul(y[i], kpow(a1[0], P - 2));
			rep(j, 0, n+1) if (j != i) {
				b1[0] = -x[j]; b1[1] = 1;
				calc(n, a1, b1);
			}
			rep(j, 0, n+1) a[j] = add(a[j], a1[j]);
		}
	}
};

const int P = 1e9 + 7, M = 20;  int L;

inline int mul(int x, int y) { return (ll)x * y % P; }
inline int add(int x, int y) { if ((x += y) >= P) x -= P; return x < 0 ? x + P : x; }

struct vec {
	int a[M];
	inline int& operator [] (int x) { return a[x]; }
	inline int operator [] (int x) const { return a[x]; }
	inline void clear() { fill_n(a, L, 0); }
	inline void operator += (const vec &b) { rep(i, 0, L) a[i] = add(a[i], b[i]); }
	inline void operator -= (const vec &b) { rep(i, 0, L) a[i] = add(a[i], -b[i]); }
	inline vec operator *= (const vec &b) {
		vec c; c.clear();
		rep(i, 0, L) if (a[i])
			for (int j = 0; i + j < L; ++j) if (b[j])
				c[i + j] = add(c[i + j], mul(a[i], b[j]));
		return *this = c;
	}
};

struct Cal {
	vec a[1 << M], b[1 << M];
	void fwt(vec a[], int len, int o = 1) {  // o=-1 UFWT
		for (int k = 0; 1 << k < len; ++k)
			rep(i, 0, len) if (~i >> k & 1) {
			int j = i ^ (1 << k);
			o == 1 ? a[j] += a[i] : a[j] -= a[i];
		}
	}
	void pow(int mask[], int len, int k, int ret[]) {
		L = k + 1;
		rep(i, 0, len) a[i].clear(), a[i][__builtin_popcount(i)] = mask[i]; 
		fwt(a, len), ret[0] = 0;
		rep(j, 1, k + 1) {
		    if (j == 1) rep(i, 0, len) b[i] = a[i];
		    else rep(i, 0, len) b[i] *= a[i];
		    int &t = ret[j] = 0;
		    rep(i, 0, len) if (__builtin_parity((len - 1) ^ i)) 
				t = add(t, -b[i][k]);else t = add(t, b[i][k]);
        }
	}
};

Cal T;
Poly<int> PP; 

const int N = 50;
int a[N], mask[1 << M], col[N], ret[N], n, m, u, v, X[N], Y[N];

void solve(int a[], int n) {
    mask[0] = 1; int L = 1 << n;
    rep(i, 1, L) {
        int t = i & -i, k = __builtin_ctz(t);
        mask[i] = mask[i ^ t] & !(i & a[k]);
    }
    T.pow(mask, L, n, col);
    rep(i, 0, n+1) X[i] = i, Y[i] = col[i];
    PP.solve(n, X, Y, ret);
}

int main() {
	cin >> n >> m;
	rep(i, 0, m) {
		cin >> u >> v;
		a[u] |= pw(v);
		a[v] |= pw(u);
	}
	solve(a, n);
	return 0;
} 

/*

Graph: link 
5 6
0 2
1 3
0 4
1 4
2 4
3 4

Color Ways
{ 0, 0, 0, 12, 144, 720 } 

Chromatic Poly
x (x - 1)^2 (x - 2)^2 = {0, 4, -12, 13, -6, 1}


Graph: link 
6 9
0 1
1 2
0 3
1 3
2 3
2 4
3 4
0 5
3 5

Color Ways
{ 0, 0, 0, 6, 192, 1620, 7680 } 

Chromatic Poly
{0, -16, 48, -56, 32, -9, 1}

*/