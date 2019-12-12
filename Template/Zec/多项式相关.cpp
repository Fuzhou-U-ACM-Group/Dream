const int M = 1 << 17 << 1;
int rev[M], ta[M], tb[M], tmp[M];

struct NTT{
	static const int G = 3, P = 998244353; //P = C*2^k + 1
	int n, N, na, nb, w[2][M], rev[M];
	void FFT(int *a, int f){
		rep(i, 0, N) if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int i = 1; i < N; i <<= 1)
			for (int j = 0, t = N / (i << 1); j < N; j += i << 1)
				for (int k = 0, l = 0, x, y; k < i; k++, l += t)
					x = (ll) w[f][l] * a[j+k+i] % P, y = a[j+k], a[j+k] = (y+x) % P, a[j+k+i] = (y-x+P) % P;
		if (f) for (int i = 0, x = kpow(N, P-2); i < N; i++) a[i] = (ll)a[i] * x % P;
	}
	int work(int len){
		for (N = 1; N < len; N <<= 1);
		if (n == N) return n; n = N;
		int d = __builtin_ctz(N);
		w[0][0] = w[1][0] = 1;
		for (int i = 1, x = kpow(G, (P-1) / N); i < N; i++) {
			rev[i] = (rev[i>>1] >> 1) | ((i&1) << (d-1));
			w[0][i] = w[1][N - i] = (ll)x * w[0][i-1] % P;
		}
		return N;
	}
	void doit(int *a, int *b, int na, int nb){ // [0, na)
		work(na + nb - 1);
		rep(i, 0, na) if (a[i] < 0) a[i] += P; rep(i, na, N) a[i] = 0;
		rep(i, 0, nb) if (b[i] < 0) b[i] += P; rep(i, nb, N) b[i] = 0;
		FFT(a, 0), FFT(b, 0);
		rep(i, 0, N) a[i] = (ll)a[i] * b[i] % P;
		FFT(a, 1);
		//rep(i, 0, N) cout << a[i] << endl;
	}
} ntt;



struct poly {
	vi a;
	inline int cs() { return sz(a) - 1; }
	inline int& operator [] (int x) { return a[x]; }
	inline void sc(int x) { a.resize(x+1); }
	inline void clr() {
		int p = cs() + 1;
		while(p && !a[p-1]) --p;
		sc(p-1);
	}
	inline void rev() { reverse(all(a)); }
	inline void dbg() {
		bool fi=0;
		for(int i=cs(); i>=0; i--) {
			a[i]=(a[i]%P+P)%P;
			if(!a[i]) continue;
			if(a[i]>P/2) a[i]-=P;
			if(fi) {
				if(i==0) printf("%+d",a[i]);
				else if(a[i]==1) printf("+");
				else if(a[i]==-1) printf("-");
				else printf("%+d",a[i]);
			} else {
				if(i==0) printf("%d",a[i]);
				else if(a[i]==1);
				else if(a[i]==-1) printf("-");
				else printf("%d",a[i]);
			}
			if(i>1) printf("x^%d",i);
			else if(i==1) printf("x");
			fi=1;
		}
		if(!fi) printf("0");
		putchar(10);
	}
};

inline poly operator * (poly a, poly b) {
	if(a.cs() < 180 || b.cs() < 180) {
		poly g;
		g.sc(a.cs()+b.cs());
		int *G = &g[0], *A = &a[0], *B = &b[0];
		for(int i=0; i<=a.cs(); i++) {
			register int*h=G+i,j=0;
			register ll x=A[i];
			for(; j<=b.cs(); ++j) h[j]=(h[j]+x*(ll)B[j])%P;
		}
		return g;
	}
	int na = a.cs()+1, nb = b.cs()+1;
	rep(i, 0, na) ta[i] = a[i];
	rep(i, 0, nb) tb[i] = b[i];
	ntt.doit(ta, tb, na, nb);
	a.sc(na+nb-2); rep(i, 0, na+nb-1) a[i] = ta[i]; a.clr();
	return a;
}

inline void ginv(poly &a, int t) {
	if(t == 1) { tb[0] = kpow(a[0], P - 2); return; }
	ginv(a, (t+1)>>1);
	int n = ntt.work(2 * t);
	rep(i, t, n) ta[i] = tb[i] = 0;
	rep(i, 0, t) ta[i] = a[i];
	ntt.FFT(ta, 0);
	ntt.FFT(tb, 0);
	rep(i, 0, n) tb[i] = mul(tb[i], P + 2 - mul(ta[i], tb[i]));
	ntt.FFT(tb, 1);
	rep(i, t, n) tb[i] = 0;
}

inline poly inv(poly a) {
	ginv(a, a.cs()+1);
	per(i, 0, a.cs()+1) a[i] = tb[i]; a.clr();
	return a;
}
inline poly operator + (poly a, poly b) {
	a.sc(max(a.cs(), b.cs()));
	per(i, 0, b.cs()+1) a[i] = add(a[i], b[i]);
	return a;
}
inline poly operator - (poly a, poly b) {
	a.sc(max(a.cs(), b.cs()));
	per(i, 0, b.cs()+1) a[i] = add(a[i], -b[i]); a.clr();
	return a;
}
inline void div(poly a, poly b, poly &d, poly &r) {
	int n = a.cs(), m = b.cs();
	if(n < m) { d.sc(0); d[0] = 0; r = a; return; }
	poly aa = a, bb = b; aa.rev(), bb.rev(), bb.sc(n - m);
	d = aa * inv(bb), d.sc(n - m), d.rev();
	r = a - b * d, r.clr();
}
inline poly operator / (poly a, poly b) {
	poly d, r;
	div(a, b, d, r);
	return d;
}
inline poly operator % (poly a, poly b) {
	a.clr(); b.clr();
	if(a.cs() < b.cs()) return a;
	poly d, r;
	div(a, b, d, r);
	return r;
}
inline poly dev(poly a) {
	rep(i, 1, a.cs()+1) a[i-1] = mul(a[i], i);
	a.sc(a.cs()-1);
	return a;
}
inline poly inte(poly a) {
	a.sc(a.cs()+1);
	per(i, 1, a.cs()+1) a[i] = mul(a[i-1], rev[i]); a[0] = 0;
	return a;
}
inline ll qz(poly &a, ll x) {
	ll ans = 0;
	per(i, 0, a.cs()+1) ans = (ans * x + a[i]) % P;
	return ans;
}

poly vvs[M];

inline void gvs(int m, int *x, int id) {
	if(m == 1) {
		vvs[id].sc(1), vvs[id][1] = 1, vvs[id][0] = add(0, -*x);
		return;
	}
	int hf = m >> 1;
	gvs(hf, x, id*2);
	gvs(m-hf, x+hf, id*2+1);
	vvs[id] = vvs[id*2] * vvs[id*2+1];
}

inline void gv(poly f, int m, int *x, int *ans, int id) {
	if(f.cs() <= 300) {
		rep(i, 0, m) ans[i] = qz(f, x[i]);
		return;
	}
	int hf = m >> 1;
	gv(f % vvs[id*2], hf, x, ans, id*2);
	gv(f % vvs[id*2+1], m-hf, x+hf, ans+hf, id*2+1);
}

inline vi getv(poly a, vi x) {
	int m = sz(x);
	if(!m) return vi();
	a.clr(); vi ans(m);
	gvs(m, &x[0], 1);
	gv(a % vvs[1], m, &x[0], &ans[0], 1);
	return ans;
}

inline poly comb(int m, int *v, int id) {
	if(m == 1) {
		poly s; s.sc(0); s[0] = *v;
		return s;
	}
	int hf = m >> 1;
	return comb(hf, v, id*2) * vvs[id*2+1] + comb(m-hf, v+hf, id*2+1) * vvs[id*2];
}

inline poly intp(vi x, vi y) {
	int m = sz(x); 
	gvs(m, &x[0], 1);
	gv(dev(vvs[1]), m, &x[0], tmp, 1);
	rep(i, 0, m) tmp[i] = mul(kpow(tmp[i], P - 2), y[i]);
	return comb(m, tmp, 1);
}

