struct Trie {
	static const int N = ::N, M = 60;
	int L, rt[N], ne[N * (M + 1)][2], cnt[N * (M + 1)], ed[N * (M + 1)];
	void init() { L = 0; }
	// 将当前数的信息存在叶子
	inline void upd(int &now, int pre, ll val, int ind, int dep = M - 1) {
		now = ++L;
		ne[now][0] = ne[pre][0];
		ne[now][1] = ne[pre][1];
		cnt[now] = cnt[pre] + 1;
		ed[now] = ed[pre];
		if(dep == -1) return ed[now] = ind, void();
		int c = val >> dep & 1;
		upd(ne[now][c], ne[pre][c], val, ind, dep - 1);
	}
	// 查询区间和 val 异或和最大的数下标
	inline int qry(int L, int R, ll val) {
		if(!(cnt[R] - cnt[L])) return -1;
		per(i, 0, M) {
			int c = val >> i & 1;
			if(cnt[ne[R][c ^ 1]] - cnt[ne[L][c ^ 1]]) c ^= 1;
			R = ne[R][c], L = ne[L][c];
		}
		return ed[R];
	}
}ac;
