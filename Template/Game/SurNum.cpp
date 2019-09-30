int sgn(ll x) {
	return !x ? 0 : (x > 0 ? 1 : -1);
}

struct Sur_Num {
	ll x, k; int op;
	Sur_Num() { x = k = op = 0; }
	Sur_Num(ll x, ll k, ll op = 0) :x(x), k(k), op(op) { }
	Sur_Num(const Sur_Num &a) { *this = a; }
	inline Sur_Num Simplify() {
		while (x % 2 == 0 && k > 0) x /= 2, k--; return *this;
	}
	friend inline int sgn(const Sur_Num &a) {
		return sgn(a.x);
	}
	inline bool Grow(int kk) {
		Simplify();
		if (kk < k) return 0;
		x *= 1ll << kk - k, k = kk;
		return 1;
	}
	friend inline void grow(Sur_Num &a, Sur_Num &b) {
		int k = max(a.k, b.k);
		a.Grow(k), b.Grow(k);
	}
	friend inline int compare(Sur_Num a, Sur_Num b) {
		if (a.op < b.op) return -1;
		if (a.op > b.op) return 1;
		if (a.op != 0) return 0;
		int opa = sgn(a), opb = sgn(b);
		if (opa < opb) return -1;
		if (opa > opb) return 1;
		grow(a, b);
		return sgn(a.x - b.x);
	}
	friend inline bool operator < (const Sur_Num &a, const Sur_Num &b) {
		return compare(a, b) == -1;
	}
	friend inline bool operator > (const Sur_Num &a, const Sur_Num &b) {
		return compare(a, b) == 1;
	}
	friend inline bool operator == (const Sur_Num &a, const Sur_Num &b) {
		return compare(a, b) == 0;
	}
	friend inline bool operator != (const Sur_Num &a, const Sur_Num &b) {
		return compare(a, b) != 0;
	}
	friend inline bool operator <= (const Sur_Num &a, const Sur_Num &b) {
		return compare(a, b) <= 0;
	}
	friend inline bool operator >= (const Sur_Num &a, const Sur_Num &b) {
		return compare(a, b) >= 0;
	}
	friend inline Sur_Num operator - (const Sur_Num &a) {
		return Sur_Num(-a.x, a.k, -a.op);
	}
	friend inline Sur_Num operator + (Sur_Num a, Sur_Num b) {
		if (a.op == 1 || b.op == 1) return Sur_Num(0, 0, 1);
		if (a.op == -1 || b.op == -1) return Sur_Num(0, 0, -1);
		grow(a, b); return Sur_Num(a.x + b.x, a.k, 0).Simplify();
	}
	friend inline Sur_Num operator - (Sur_Num a, Sur_Num b) {
		return a + (-b);
	}
	friend inline Sur_Num operator += (Sur_Num &a, Sur_Num b) {
		return a = a + b;
	}
	friend inline Sur_Num operator -= (Sur_Num &a, Sur_Num b) {
		return a = a - b;
	}
	friend inline Sur_Num operator >> (Sur_Num a, ll k) {
		return a.k += k, a.Simplify();
	}
	friend inline Sur_Num getMid(Sur_Num a, Sur_Num b) {
		return a + b >> 1;
	}
	inline void print() const {
		printf("Sur_Num:\n");
		if (op == 1) { printf("+inf\n"); return; }
		if (op == -1) { printf("-inf\n"); return; }
		printf("%lld/%lld\n", x, 1 << k);
	}
	inline static Sur_Num read() {
		ll a1, a2, a3;
		scanf("%lld%lld%lld", &a1, &a2, &a3);
		return Sur_Num(a1, a2, a3).Simplify();
	}
} _0(0, 0, 0), _inf(0, 0, 1);

struct Sur_Tri {
	Sur_Num p, x, q;
	Sur_Tri() { p = x = q = _0; }
	Sur_Tri(Sur_Num p, Sur_Num x, Sur_Num q) :p(p), x(x), q(q) {}
	Sur_Tri(const Sur_Tri &a) { *this = a; }
	Sur_Tri goRight() {
		Sur_Num y;
		if (x.x >= 0 && x.k == 0) y = x, y.x++; else y = x + q >> 1;
		return Sur_Tri(x, y, q);
	}
	Sur_Tri goLeft() {
		Sur_Num y;
		if (x.x <= 0 && x.k == 0) y = x, y.x--; else y = p + x >> 1;
		return Sur_Tri(p, y, x);
	}
	void print() {
		printf("\n\nSur_Tri:\n\n");
		p.print(), x.print(), q.print();
		printf("\nend\n\n");
	}
};

struct Sur_Calculator {
	int getDir(Sur_Tri S, Sur_Num a, Sur_Num b) {
		if (a < S.x && S.x < b) return 0;
		if (a <= S.x && b <= S.x) return -1;
		if (a >= S.x && b >= S.x) return 1;
		assert(0);
	}
	Sur_Num getValue(Sur_Num a, Sur_Num b) {
		int op;
		Sur_Tri S(-_inf, _0, _inf);
		while (op = getDir(S, a, b)) S = ((op == 1) ? S.goRight() : S.goLeft());
		return S.x;
	}
};
