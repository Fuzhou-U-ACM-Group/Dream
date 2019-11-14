#define M 1001000
int n, a[M]; long long k;
struct Segtree{
	Segtree *ls, *rs;
	long long sum, pos;
	Segtree(Segtree *_, Segtree *__, long long ___, long long ____):
		ls(_), rs(__), sum(___), pos(____){}
	friend Segtree* Insert(Segtree *p, int l, int r, long long x, long long val, long long pos){
		int mid = l + r >> 1;
		if(l == r)return new Segtree(0x0, 0x0, val, pos);
		if(x <= mid){
            Segtree *temp = Insert(p->ls, l, mid, x, val, pos);
            return new Segtree(temp, p->rs, min(temp->sum + p->rs->sum, k+1), 0);
		}
		else{
            Segtree *temp = Insert(p->rs, mid+1, r, x, val, pos);
            return new Segtree(p->ls, temp, min(temp->sum + p->ls->sum, k+1), 0);
		}
	}
	friend int Find(Segtree *p, int l, int r){
		int mid = l + r >> 1;
		if(l == r)return p->pos;
		if(k <= p->ls->sum) return Find(p->ls, l, mid);
		else{
			k -= p->ls->sum;
			return Find(p->rs, mid+1, r);
		}
	}
};
// 求字典序第 k 小的子序列 
Segtree *tree[M];
int st[M], top;
int main(){
	cin >> n >> k; 
	int mx = 0;
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), mx = max(mx, a[i]);
	tree[n+1] = new Segtree(0x0, 0x0, 0, 0);
	tree[n+1]->ls = tree[n+1]->rs = tree[n+1];
	for(int i = n+1; i >= 0; i --)
	    tree[i-1] = Insert(tree[i], 0, mx, a[i], i == n+1 ? 1 : tree[i]->sum, i);
	if(k > tree[0]->sum) return puts("-1"), 0;
	int now = 0;
	while(true){
		now = Find(tree[now], 0, mx);
		if(now == n+1)break;
		st[++ top] = a[now];
	}
	printf("%d\n", top);
	for(int i = 1; i <= top; i ++) printf("%d ", st[i]);
	return 0;
}
