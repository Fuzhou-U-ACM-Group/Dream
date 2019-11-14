#pragma once
#include <cassert>
#include <algorithm>
using ll = long long;
using ull = unsigned long long;
using uill = __uill_t;
// return a % b
inline ull mod128_64_small(uill a, ull b) {
  ull q, r;
  __asm__ (
    "divq\t%4"
    : "=a"(q), "=d"(r)
    : "0"(ull(a)), "1"(ull(a >> 64)), "rm"(b)
  );
  return r;
}
// mod should be not greater than 2^62 (about 4e18)
// return a * b % mod when mod is less than 2^31
inline ull mul_mod(ull a, ull b, ull mod) {
  assert(0 <= a && a < mod);
  assert(0 <= b && b < mod);
  if (mod < int(1e9)) return a * b % mod;
  ull k = (ull)((long double)a * b / mod);
  ull res = a * b - k * mod;
  if ((ll)res < 0) res += mod;
  return res;
}
inline ll add_mod(ll x, ll y, ll mod) { return (x + y) % mod; }
inline ll sub_mod(ll x, ll y, ll mod) { return (x - y + mod) % mod; }
inline ull mul_add_mod(ull a, ull b, ull c, ull mod) {
  return mod128_64_small(uill(a) * b + c, mod);
}
ll pow_mod(ll a, ll n, ll m) {
  ll res = 1;
  for (a %= m; n; n >>= 1) {
    if (n & 1) res = mul_mod(res, a, m);
    a = mul_mod(a, a, m);
  }
  return res;
}
template<typename T>
T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
// ax + by = gcd(a, b), |x| + |y| is minimum
void exgcd(ll a, ll b, ll &g, ll &x, ll &y) {
  if (!b) x = 1, y = 0, g = a;
  else {
    exgcd(b, a % b, g, y, x);
    y -= x * (a / b);
  }
}
// return x, where ax = 1 (mod mod)
ll mod_inv(ll a, ll mod) {
  if (gcd(a, mod) != 1) return -1;
  ll b = mod, s = 1, t = 0;
  while (b) {
    ll q = a / b;
    std::swap(a -= q * b, b);
    std::swap(s -= q * t, t);
  }
  return s < 0 ? s + mod : s;
}
ull crt2(ull r1, ull mod1, ull r2, ull mod2) {
  ull inv = mod_inv(mod1, mod2);
  return mul_mod(r2 + mod2 - r1,  inv, mod2) * mod1 + r1;
}
//ax + by = c,x >= 0, x is minimum
//xx = x + t * b, yy = y - t * a
bool linear_equation(ll a, ll b, ll c, ll &x, ll &y) {
  ll g;
  exgcd(a,b,g,x,y);
  if (c % g) return false;
  b /= g, a /= g, c /= g;
  x = (x % b * (c % b) % b + b) % b;
  y = (c - a * x) / b;
  return true;
}
// 求n的欧拉函数值，简易版
ll euler_phi(ll n) {
  ll ret = n;
  for (ll i = 2; i * i <= n; ++i) if (n % i == 0) {
    ret = ret / i * (i - 1);
    while (n % i == 0) n /= i;
  }
  if (n > 1) ret = ret / n * (n - 1);
  return ret;
}