using uint128 = __uint128_t;
using ull = unsigned long long;
using ll = long long;
using uint = unsigned int;
using pli = pair<ull, uint>;

namespace prime {
#define eb emplace_back
	ull mod;
	inline ull mul(ull a, ull b) {
  		if (mod < int(2e9)) return a * b % mod;
  		ull k = ((long double)a * b / mod + 0.1);
  		ull res = a * b - k * mod;
  		if ((ll)res < 0) res += mod;
  		return res;
	}
	inline ull add(ull a, ull b) {
		if ((a += b) >= mod) a -= mod;
		return a;
	}
	inline ull kpow(ull a, ull b) {
		ull res = 1;
		for (; b; a = mul(a, a), b >>= 1) if (b & 1) res = mul(res, a);
		return res;
	}
	inline ull sqr(ull x) { return x * x; }
	bool composite(ull n, const uint* base, int m) {
		int s = __builtin_ctzll(n - 1);
		ull d = (n - 1) >> s; mod = n;
		for (int i = 0, j; i < m; ++i) {
			ull a = kpow(base[i], d);
			if (a == 1 || a == n - 1) continue;
			for (j = s - 1; j > 0; --j) { a = mul(a, a); if (a == n - 1) break; }
			if (j == 0) return 1;
		}
		return 0;
	}
	bool is_prime(ull n) { // reference: http://miller-rabin.appspot.com
		assert(n < (ull(1) << 63));
		static const uint base[][7] = {
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
		return !composite(n, base[x], y);
	}
	vector<uint> primes;
	void init(uint n) {
		uint sq = sqrt(n);
		vector<bool> isp(n + 1, 1);
		primes.clear();
		for (uint i = 2; i <= sq; ++i) if (isp[i]) {
			if (i != 2) primes.pb(i);
			for (uint j = i * i; j <= n; j += i) isp[j] =  0;
		}
	}
	ull brent(ull n, ull c) { // n must be composite and odd.
		const ull s = 256;
		ull y = 1; c %= n; mod = n;
		for (ull l = 1; ; l <<= 1) {
			ull x = y;
			for (int i = 0; i < l; ++i) y = add(mul(y, y), c);
			ull p = 1;
			for (int k = 0; k < l; k += s) {
				ull sy = y;
				for (int i = 0; i < min(s, l - k); ++i) {
					y = add(mul(y, y), c);
					p = mul(p, add(y, n - x));
				}
				ull g = __gcd(n, p);
				if (g == 1) continue;
				if (g == n) for (g = 1, y = sy; g == 1; ) y = add(mul(y, y), c), g = __gcd(n, add(y, n - x));
				return g;
			}
		}
	}
	vector<pli> factors(ull n) {
		assert(n < (1ull << 63));
		if (n <= 1) return {};
		vector<pli> ret;
		if (!(n & 1)) {
			uint e = __builtin_ctzll(n);
			ret.eb(2, e);
			n >>= e;
		}
		ull lim = sqr(primes.back());
		for (auto &&p: primes) {
			if (sqr(p) > n) break;
			uint e = 0;
			while (n % p == 0) n /= p, e++;
			if (e) ret.eb(p, e);
		}
		uint s = sz(ret);
		while (n > lim && !is_prime(n)) {
			for (ull c = 1; ; ++c) {
				ull p = brent(n, c);
				if (!is_prime(p)) continue;
				uint e = 1; n /= p;
				while (n % p == 0) n /= p, e++;
				ret.eb(p, e);
				break;
			}
		}
		if (n > 1) ret.eb(n, 1);
		if (sz(ret) - s >= 2) sort(ret.begin() + s, ret.end());
		return ret;
	}
}
