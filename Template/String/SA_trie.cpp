// trie 树点带字母，每个点到根的字符串排序， O(nlogn)
// C 为字符集大小，从 a 开始， M 为倍增深度
// 调用 Init 之后，取 sa[]
const int N = 5e5, M = 21, C = 26;
int n, fa[N]; char s[N];
struct SA {
	int R[N], RF[N], tmp[N], pos[N], tax[N], tp[N], sa[N], siz, n, pa[N][M];
	int h(int c) { return c - 'a' + 1; }
	void Qsort(int *sa, int *R, int *tp, int siz) {
		rep(i, 0, siz + 1) tax[i] = 0;
		rep(i, 1, n + 1) tax[R[tp[i]]]++;
		rep(i, 1, siz + 1) tax[i] += tax[i - 1];
		per(i, 1, n + 1) sa[tax[R[tp[i]]]--] = tp[i];
	}
	// s[] 表示字母点权，下标从 1 开始
	// fa[] 表示树上父节点编号，根为 1 
	void Init(int _n, int fa[], char s[]) {
		n = _n, pa[1][0] = 0; rep(i, 2, n + 1) pa[i][0] = fa[i];
		rep(i, 2, n + 1) rep(j, 1, M) pa[i][j] = pa[pa[i][j - 1]][j - 1];
		rep(i, 1, n + 1) R[i] = h(s[i]), tp[i] = i;
		Qsort(sa, R, tp, C); rep(i, 1, n + 1) pos[sa[i]] = i;
		for (int w = 1, p = 0; w < n; w <<= 1, p++) {
			rep(i, 1, n + 1) RF[i] = pos[pa[i][p]];
			Qsort(tp, RF, sa, n);
			Qsort(sa, R, tp, R[sa[n]]);
			rep(i, 1, n + 1) tmp[i] = R[i]; R[sa[1]] = 1;
			rep(i, 2, n + 1) R[sa[i]] =
				(tmp[sa[i]] == tmp[sa[i - 1]] && tmp[pa[sa[i]][p]] == tmp[pa[sa[i - 1]][p]]) ?
					R[sa[i - 1]] : R[sa[i - 1]] + 1;
			rep(i, 1, n + 1) pos[sa[i]] = i;
		}
	}
} T;
