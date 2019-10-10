using uint128 = __uint128_t;
using ull = unsigned long long;
using ll = long long;
using uint = unsigned int;
using pli = pair<ull, uint>;
namespace prime {
	inline ull sqr(ull x) { return x * x; }
	inline uint isqrt(ull x) { return sqrtl(x); }
	inline uint ctz(ull x) { return __builtin_ctzll(x); }
	template <class T>
	T gcd(T a, T b) {  while (b) { T t = a % b; a = b; b = t; } return a; }
	
	template <class T, class dT, class sT>
	struct Mod {
		static T mod, inv, r2;
		static const int wb = sizeof(T) * 8;
		T x;
		Mod(): x(0) {}
		Mod(T _x): x(init(_x)) {}
		bool operator == (const Mod& rhs) const { return x == rhs.x; }
		bool operator != (const Mod& rhs) const { return x != rhs.x; }
		Mod operator += (const Mod& rhs) { if ((x += rhs.x) >= mod) x -= mod; return *this; }
		Mod operator -= (const Mod& rhs) { if (sT(x -= rhs.x) < 0) x += mod; return *this; }
		Mod operator *= (const Mod& rhs) { x = reduce(dT(x) * rhs.x); return *this; }
		Mod operator + (const Mod &rhs) const { return Mod(*this) += rhs; }
		Mod operator - (const Mod &rhs) const { return Mod(*this) -= rhs; }
		Mod operator * (const Mod &rhs) const { return Mod(*this) *= rhs; }
		Mod operator - () const { return Mod() - *this; }
		Mod pow(ull e) const {
			Mod r(1); for (Mod a = *this; e; e >>= 1, a *= a) if (e & 1) r *= a;
			return r;
		}
		T get() const { return reduce(x); }
		static T modulus() { return mod; }
		static T init(T w) { return reduce(dT(w) * r2); }
		static void set_mod(T m) { mod = m, inv = mul_inv(mod), r2 = -dT(mod) % mod; }
		static T reduce(dT x) {
			T y = T(x >> wb) - T((dT(T(x) * inv) * mod) >> wb);
			return sT(y) < 0 ? y + mod : y;
		}
		static T mul_inv(T n, int e = 6, T x = 1) {
			return !e ? x : mul_inv(n, e - 1, x * (2 - x * n));
		}	
	};
	
	using Mod64 = Mod<ull, uint128, ll>;
	using Mod32 = Mod<uint, ull, int>;
	template <> ull Mod64::mod = 0;
	template <> ull Mod64::inv = 0;
	template <> ull Mod64::r2 = 0;
	template <> uint Mod32::mod = 0;
	template <> uint Mod32::inv = 0;
	template <> uint Mod32::r2 = 0;
	
	template <class T, class mod>
	bool composite(T n, const uint* bases, int m) {
		mod :: set_mod(n);
		int s = __builtin_ctzll(n - 1);
		T d = (n - 1) >> s;
		mod one(1), fone(n - 1);
		for (int i = 0, j; i < m; ++i) {
			mod a = mod(bases[i]).pow(d);
			if (a == one || a == fone) continue;
			for (j = s - 1; j > 0; --j) { if ((a *= a) == fone) break; }
			if (j == 0) return 1;
		}
		return 0;
	}
	bool is_prime(ull n) { // reference: http://miller-rabin.appspot.com
		assert(n < (ull(1) << 63));
		static const uint bases[][7] = {
			{2, 3},
			{2, 299417},
			{2, 7, 61},
			{15, 176006322, 4221622697u},
			{2, 2570940, 211991001, 3749873356u},
			{2, 2570940, 880937, 610386380, 4130785767u},
			{2, 325, 9375, 28178, 450775, 9780504, 1795265022}
		};
		if (n <= 1) return 0;
		if (!(n & 1)) return n == 2;
		if (n <= 8) return 1;
		int x = 6, y = 7;
		if (n < 1373653) x = 0, y = 2;
		else if (n < 19471033) x = 1, y = 2;
		else if (n < 4759123141) x = 2, y = 3;
		else if (n < 154639673381) x = y = 3;
		else if (n < 47636622961201) x = y = 4;
		else if (n < 3770579582154547) x = y = 5;
		if (n < (1u << 31)) return !composite<uint, Mod32>(n, bases[x], y);
		return !composite<ull, Mod64>(n, bases[x], y);
	}
	struct ExactDiv {
		ExactDiv() {}
		ExactDiv(ull n) : n(n), i(Mod64::mul_inv(n)), t(ull(-1) / n) {}
		friend ull operator / (ull n, ExactDiv d) { return n * d.i; };
		bool divide(ull n) { return n / *this <= t; }
		ull n, i, t;
	};
	vector<ExactDiv> primes;
	void init(uint n) {
		uint sqrt_n = sqrt(n);
		vector<bool> is_prime(n + 1, 1);
		primes.clear();
		for (uint i = 2; i <= sqrt_n; ++i) if (is_prime[i]) {
			if (i != 2) primes.pb(ExactDiv(i));
			for (uint j = i * i; j <= n; j += i) is_prime[j] =  0;
		}
	}
	
	template <class T, class mod>
	T brent(T n, T c) { // n must be composite and odd.
		const ull s = 256;
		mod::set_mod(n);
		const mod one = mod(1), mc = mod(c);
		mod y = one;
		for (ull l = 1; ; l <<= 1) {
			auto x = y;
			for (int i = 0; i < (int)l; ++i) y = y * y + mc;
			mod p = one;
			for (int k = 0; k < (int)l; k += s) {
				auto sy = y;
				for (int i = 0; i < (int)min(s, l - k); ++i) {
					y = y * y + mc;
					p *= y - x;
				}
				T g = gcd(n, p.x);
				if (g == 1) continue;
				if (g == n) for (g = 1, y = sy; g == 1; ) y = y * y + mc, g = gcd(n, (y - x).x);
				return g;
			}
		}
	}
	ull brent(ull n, ull c) {
		if (n < (1u << 31)) return brent<uint, Mod32>(n, c);
		return brent<ull, Mod64>(n, c);
	}
	vector<pli> factors(ull n) {
		assert(n < (1ull << 63));
		if (n <= 1) return {};
		vector<pli> ret;
		ull v2 = sqrtl(n), v3 = cbrtl(n), v = v2, b = 2;
		if (v2 * v2 == n || v3 * v3 * v3 == n) {
			if (v2 * v2 != n) v = v3, b = 3;
			ret = factors(v);
			for (auto &&e: ret) e.se *= b;
			return ret;
		}
		if (!(n & 1)) {
			uint e = ctz(n);
			ret.emplace_back(2, e);
			n >>= e;
		}
		ull lim = sqr(primes.back().n);
		for (auto &&p: primes) {
			if (sqr(p.n) > n) break;
			if (p.divide(n)) {
				uint e = 1; n = n / p;
				while (p.divide(n)) n = n / p, e++;
				ret.emplace_back(p.n, e);
			}
		}
		uint s = ret.size();
		while (n > lim && !is_prime(n)) {
			for (ull c = 1; ; ++c) {
				ull p = brent(n, c);
				if (!is_prime(p)) continue;
				uint e = 1; n /= p;
				while (n % p == 0) n /= p, e += 1;
				ret.emplace_back(p, e);
				break;
			}
		}
		if (n > 1) ret.emplace_back(n, 1);
		if (ret.size() - s >= 2) sort(ret.begin() + s, ret.end());
		return ret;
	}
}
