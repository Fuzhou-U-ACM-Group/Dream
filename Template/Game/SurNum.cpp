int sgn(ll x) { return !x ? 0 : (x > 0 ? 1 : -1); }
struct SurNum {
	ll x, k; int op;
	SurNum() { x = k = op = 0; }
	SurNum(ll x, ll k, ll op = 0) :x(x), k(k), op(op) { }
	SurNum(const SurNum &a) { *this = a; }
	inline SurNum Simplify() {
		while (x % 2 == 0 && k > 0) x /= 2, k--; 
		return *this;
	}
	friend inline int sgn(const SurNum &a) { return sgn(a.x); }
	inline bool Grow(int kk) {
		Simplify();
		if (kk < k) return 0;
		x *= 1ll << kk - k, k = kk;
		return 1;
	}
	friend inline void grow(SurNum &a, SurNum &b) {
		int k = max(a.k, b.k);
		a.Grow(k), b.Grow(k);
	}
	friend inline int compare(SurNum a, SurNum b) {
		if (a.op < b.op) return -1;
		if (a.op > b.op) return 1;
		if (a.op != 0) return 0;
		int opa = sgn(a), opb = sgn(b);
		if (opa < opb) return -1;
		if (opa > opb) return 1;
		grow(a, b);
		return sgn(a.x - b.x);
	}
	friend inline bool operator < (const SurNum &a, const SurNum &b) {
		return compare(a, b) == -1;
	}
	friend inline bool operator > (const SurNum &a, const SurNum &b) {
		return compare(a, b) == 1;
	}
	friend inline bool operator == (const SurNum &a, const SurNum &b) {
		return compare(a, b) == 0;
	}
	friend inline bool operator != (const SurNum &a, const SurNum &b) {
		return compare(a, b) != 0;
	}
	friend inline bool operator <= (const SurNum &a, const SurNum &b) {
		return compare(a, b) <= 0;
	}
	friend inline bool operator >= (const SurNum &a, const SurNum &b) {
		return compare(a, b) >= 0;
	}
	friend inline SurNum operator - (const SurNum &a) {
		return SurNum(-a.x, a.k, -a.op);
	}
	friend inline SurNum operator + (SurNum a, SurNum b) {
		if (a.op == 1 || b.op == 1) return SurNum(0, 0, 1);
		if (a.op == -1 || b.op == -1) return SurNum(0, 0, -1);
		grow(a, b); return SurNum(a.x + b.x, a.k, 0).Simplify();
	}
	friend inline SurNum operator - (SurNum a, SurNum b) {
		return a + (-b);
	}
	friend inline SurNum operator += (SurNum &a, SurNum b) {
		return a = a + b;
	}
	friend inline SurNum operator -= (SurNum &a, SurNum b) {
		return a = a - b;
	}
	friend inline SurNum operator >> (SurNum a, ll k) {
		return a.k += k, a.Simplify();
	}
	friend inline SurNum getMid(SurNum a, SurNum b) {
		return a + b >> 1;
	}
	inline void print() const {
		printf("SurNum:\n");
		if (op == 1) { printf("+inf\n"); return; }
		if (op == -1) { printf("-inf\n"); return; }
		printf("%lld/%lld\n", x, 1 << k);
	}
	inline static SurNum read() {
		ll a1, a2, a3;
		scanf("%lld%lld%lld", &a1, &a2, &a3);
		return SurNum(a1, a2, a3).Simplify();
	}
} _0(0, 0, 0), _inf(0, 0, 1);
struct SurTri {
	SurNum p, x, q;
	SurTri() { p = x = q = _0; }
	SurTri(SurNum p, SurNum x, SurNum q) :p(p), x(x), q(q) {}
	SurTri(const SurTri &a) { *this = a; }
	SurTri goRight() {
		SurNum y;
		if (x.x >= 0 && x.k == 0) y = x, y.x++; else y = x + q >> 1;
		return SurTri(x, y, q);
	}
	SurTri goLeft() {
		SurNum y;
		if (x.x <= 0 && x.k == 0) y = x, y.x--; else y = p + x >> 1;
		return SurTri(p, y, x);
	}
	void print() {
		printf("\n\nSurTri:\n\n");
		p.print(), x.print(), q.print();
		printf("\nend\n\n");
	}
};
struct SurCalculator {
	int getDir(SurTri S, SurNum a, SurNum b) {
		if (a < S.x && S.x < b) return 0;
		if (a <= S.x && b <= S.x) return -1;
		if (a >= S.x && b >= S.x) return 1;
		assert(0);
	}
	SurNum getValue(SurNum a, SurNum b) {
		int op;
		SurTri S(-_inf, _0, _inf);
		while (op = getDir(S, a, b)) S = ((op == 1) ? S.goRight() : S.goLeft());
		return S.x;
	}
};