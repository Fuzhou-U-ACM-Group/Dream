typedef unsigned long long ull;
typedef __uint128_t dw;
typedef vector<ull> vl;

ll mod_inv(ll a, ll mod) {
  if (__gcd(a, mod) != 1) return -1;
  ll b = mod, s = 1, t = 0;
  while (b) {
    ll q = a / b;
    swap(a -= q * b, b);
    swap(s -= q * t, t);
  }
  return s < 0 ? s + mod : s;
}


// n! / p^{v_p(n!)} mod p^e, assume p^e < 2^63 - 1, pe < 10^6
// (n!)_p = \stirlingfirst{p}{1}^u f_{p,e}(u) \sum_{k=0}^{e-1} (up)^k \stirlingfirst{v+1}{k+1} \bmod p^e
// f_{p,e} = \prod_{i=0}^{x-1}(1 + \sum_{k=1}^{e-1}\frac{\stirlingfirst{p}{k+1}}{\stirlingfirst{p}{1}} (ip)^k)
ull fact_pe(ull n, ull p, ull e) {
  vl pows(e + 1, 1);
  ull pe = 1, min_pe = min(p, e);
  rep(i, 1, e+1) pows[i] = (pe *= p);
  ull period = pe / p * 2, deg = e * 2 - 1;
  if (p == 2 && e >= 3) period >>= 1;

  // first kind stirling number: O(p * min(p, e))
  vl s1(p * min_pe); s1[0] = 1;
  rep(i, 1, p) {
    int o = i * min_pe;
    s1[o] = (dw)s1[o - min_pe] * i % pe;
    rep(j, 1, min_pe) 
      s1[o + j] = (s1[o + j - min_pe - 1] + (dw)s1[o + j - min_pe] * i) % pe;
  }

  // product of {up + 1, ..., up + v} mod p^e
  auto fact_range = [&] (ull u, ull v) {
    ull coef = (dw)u % pe * p % pe, prod = 1, ret = 0;
    for (ull k = 0; k < min_pe; ++k) {
      ret = (ret + (dw)prod * s1[v * min_pe + k]) % pe;
      prod = (dw)prod * coef % pe;
    }
    return ret;
  };

  // f_{p,e}(0..2e-2): O(e * min(p, e) + e log(p))
  ull fac = fact_range(0, p - 1), ifac = mod_inv(fac, pe);
  vl f_pe(deg, 1);
  for (ull i = 1; i < deg; ++i) {
    f_pe[i] = (dw)f_pe[i - 1] * fact_range(i - 1, p - 1) % pe * ifac % pe;
  }

  // coprime factorials: O(e + e log(p))
  vl cifac(deg, 1), cfac_vs(deg);
  ull prod = 1;
  for (ull i = 1; i < deg; ++i) {
    ull j = i, v = 0;
    for (; j % p == 0; j /= p, ++v);
    cfac_vs[i] = cfac_vs[i - 1] + v;
    cifac[i - 1] = j;
    prod = (dw)prod * j % pe;
  }
  cifac[deg - 1] = mod_inv(prod, pe);
  for (int i = deg - 2; i >= 0; --i) {
    cifac[i] = (dw)cifac[i + 1] * cifac[i] % pe;
  }

  // find the value of f_{p, e}(x): O(e log x)
  auto evaluate = [&](ull x) {
    if (x < deg) return f_pe[x];
    vl vs(deg), inv(deg);
    ull v = 0, prod = 1;
    for (ull i = 0; i < deg; ++i) {
      ull m = x - i;
      for (; m % p == 0; m /= p, ++vs[i]);
      v += vs[i];
      inv[i] = prod;
      prod = (dw)prod * m % pe;
    }
    ull iprod = mod_inv(prod, pe);
    for (int i = deg - 1; i >= 0; --i) {
      inv[i] = (dw)iprod * inv[i] % pe;
      iprod = (dw)iprod * ((x - i) / pows[vs[i]]) % pe;
    }
    ull ret = 0;
    for (ull i = 0; i < deg; ++i) {
      ull j = deg - 1 - i, ex = v - vs[i] - cfac_vs[i] - cfac_vs[j];
      if (ex >= e) continue;
      ull add = (dw)cifac[j] * cifac[i] % pe;
      if (j & 1) add = pe - add;
      add = (dw)pows[ex] * prod % pe * inv[i] % pe * add % pe * f_pe[i] % pe;
      ret = (ret + add) % pe;
    }
    return ret;
  };

  // ((up+v)!)_p mod p^e: O(min(p, e))
  auto fact_p = [&](ull u, ull v) {
    return (dw)fact_range(u, v) * evaluate(u) % pe;
  };
  
  ull ret = 1, ex = 0;
  while (n > 0) {
    ull q = n / p, v = n % p;
    ull u = q % period;
    ret = (dw)ret * fact_p(u, v) % pe;
    ex += u, n = q;
  }
  for (ex %= period; ex; ex >>= 1) {
    if (ex & 1) ret = (dw)ret * fac % pe;
    fac = (dw)fac * fac % pe;
  }
  return ret;
}
