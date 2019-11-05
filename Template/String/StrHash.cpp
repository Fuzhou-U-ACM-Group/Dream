const int P = 1e9 + 7, N = 101010;
struct Str {
	int B[N], h[N], ba;
	Str(int ba) : ba(ba) { 
		B[0] = 1; rep(i, 1, N) B[i] = mul(B[i - 1], ba);
	}
	int upd(int a, int b) {
		if((a += b) >= P) a -= P;
		return a < 0 ? a + P : a;
	}
	int mul(int a, int b) { return 1ll * a * b % P; }
	void init(vi &s) {
		h[0] = s[0] + 1; rep(i, 1, sz(s)) h[i] = upd(mul(h[i - 1], ba), s[i] + 1);
	}
	int sub(int l, int r) {
		if(!l) return h[r];
		return upd(h[r], -mul(h[l - 1], B[r - l + 1]));
	}
}ha1(233), ha2(241);
