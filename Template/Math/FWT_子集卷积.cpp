const int P = 1e9 + 7, M = 18;
inline int mul(int x, int y) { return (ll)x*y%P; }
inline int add(int x, int y) { return (x += y) >= P ? x - P : x; }

template <int L>
struct Num {
	array<int, L> a;
	inline int& operator [] (int x) { return a[x]; }
	inline int operator [] (int x) const { return a[x]; }
	inline void clear() { a.fill(0); }
	inline void operator += (const Num &b) {
		rep(i, 0, L) a[i] = add(a[i], b[i]);
	}
	inline void operator -= (const Num &b) {
		rep(i, 0, L) a[i] = add(a[i], P - b[i]);
	}
	inline friend Num operator * (const Num &a, const Num &b) {
		Num<L> c; c.clear();
		rep(i, 0, L) if (a[i])
			for (int j = 0; i + j < L; ++j) if (b[j])
				c[i + j] = add(c[i + j], mul(a[i], b[j]));
		return c;
	}
};

template <class V>
struct Calculator {
	V aa[1 << M], bb[1 << M];
	void fwt(V a[], int len, int o = 1) {  // o=-1 UFWT
		for (int k = 0; 1 << k < len; ++k)
			rep(i, 0, len) if (~i >> k & 1) {
			int j = i ^ (1 << k);
			(o == 1) ? a[j] += a[i] : a[j] -= a[i];
		}
	}
	void mul(V a[], V b[], int len, V c[]) {
		fwt(a, len), fwt(b, len);
		rep(i, 0, len) c[i] = a[i] * b[i];
		fwt(c, len, -1);
	}
	void pow(V a[], int len, int k, V c[]) {
		fwt(a, len);
		rep(i, 0, len) {
			c[i] = a[i];
			rep(j, 0, k - 1) c[i] = c[i] * a[i];
		}
		fwt(c, len, -1);
	}
	void In(int A[], int len, V a[]) {
		rep(i, 0, len) a[i].clear(), a[i][__builtin_popcount(i)] = A[i];
	}
	void Out(V a[], int len, int A[]) {
		rep(i, 0, len) A[i] = a[i][__builtin_popcount(i)];
	}
	void Mul(int A[], int B[], int len, int C[]) {
		In(A, len, aa), In(B, len, bb), mul(aa, bb, len, aa), Out(aa, len, C);
	}
	void Pow(int A[], int len, int k, int C[]) {
		In(A, len, aa), pow(aa, len, k, bb), Out(bb, len, C);
	}
	void ModP(int a[], int len) {
		rep(i, 0, len) a[i] = add(a[i], P);
	}
};

Calculator<Num<M + 1>> T;

/*

集合幂级数用于计算快速子集卷积

In 装箱操作，将普通数组封装成集合幂级数
Out 拆箱操作，将集合幂级数转化为普通数组
Mul 计算子集卷积
Pow 计算多重子集自卷积
M 为 bit 数，数组范围 [0,2^M-1] , Num 范围 [0,M]
多组数据， L 可改造用以减少计算量

*/