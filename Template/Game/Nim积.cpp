/*
 * 注：高维硬币游戏
 */
namespace Nim {
	int nimPow(int x, int y) {
		if (x < 2) return x && y; int a = 0;
		while (x < (1 << (1 << a)) || x >= (1 << (1 << (a + 1)))) a++;
		int m = 1 << (1 << a), p = x / m, s = y / m, t = y%m;
		int d1 = nimPow(p, s), d2 = nimPow(p, t);
		return (m*(d1^d2)) ^ nimPow(m / 2, d1);
	}
	int Mul(int x, int y) {
		if (x < y) return Mul(y, x);
		if (x < 2) return x && y; int a = 0;
		while (x < (1 << (1 << a)) || x >= (1 << (1 << (a + 1)))) a++;
		int m = 1 << (1 << a), p = x / m, q = x%m, s = y / m, t = y%m;
		int c1 = Mul(p, s), c2 = Mul(p, t) ^ Mul(q, s), c3 = Mul(q, t);
		return (m*(c1^c2)) ^ c3^nimPow(m / 2, c1);
	}
}