const int N = 1e6 + 7, P = 998244353;
int n, fv[N];
ll f[N];
void init(int n) {
	f[0] = f[1] = 1;
	int m = sqrt(n) + 1;
	rep(i, 1, m+1) fv[i] = i * (3 * i - 1) / 2;
	rep(i, 2, n+1) {
		for(int j = 1; fv[j] <= i; j++) {
			f[i] += j & 1 ? f[i - fv[j]] : -f[i - fv[j]];
			if (fv[j] + j <= i) 
				f[i] += j & 1 ? f[i - fv[j] - j] : -f[i - fv[j] - j];
		}
		f[i] = (f[i] % P + P) % P;
	}
}