int n; ll a[N];
struct Seg {
	static const int N = ::N << 2;
	ll sum[N], la[N];
	void build(int l = 1, int r = n, int rt = 1) {
		la[rt] = 0;
		if(l == r) return sum[rt] = a[l], void();
		int mid = l + r >> 1;
		build(l, mid, ls); build(mid + 1, r, rs);
		sum[rt] = sum[ls] + sum[rs];
	}
	void upd(int L, int R, ll c, int l = 1, int r = n, int rt = 1) {
		sum[rt] += c * (min(R, r) - max(L, l) + 1);
		if(L <= l && r <= R) return la[rt] += c, void();
		int mid = l + r >> 1;
		if(L <= mid) upd(L, R, c, l, mid, ls);
		if(R > mid) upd(L, R, c, mid + 1, r, rs);
	}
	ll qry(int L, int R, int l = 1, int r = n, int rt = 1) {
		if(L <= l && r <= R) return sum[rt];
		ll ans = la[rt] * (min(R, r) - max(L, l) + 1);
		int mid = l + r >> 1;
		if(L <= mid) ans += qry(L, R, l, mid, ls);
		if(R > mid) ans += qry(L, R, mid + 1, r, rs);
		return ans;
	}
}seg;
