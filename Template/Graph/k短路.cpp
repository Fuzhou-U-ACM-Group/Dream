// S -> T 可重复经过点的第 K 短路
// time : O(klogk + mlogn) space : O(nlogn)  
const int N = 5050, M = 200005, B = 20;
const db eps = 1e-9, inf = 1e16;
db dis[N], w;
bool vis[N], tree[M];
int n, m, S, T, fa[N], st[N], top, u, v;

struct Graph{
	int h[N], ne[M], to[M], e;
	db w[M];
	inline void add(int u, int v, db val){
		ne[++e] = h[u], h[u] = e, to[e] = v, w[e] = val;
	}
} g, rg;

void Dij(){
	rep(i, 1, n+1) dis[i] = inf;
	priority_queue<pair<db, int> > pq;
	pq.push(mp(dis[T] = 0, T));
	while(!pq.empty()){
		int u = pq.top().se; pq.pop();
		if (vis[u]) continue; vis[u] = 1;
		for (int i = rg.h[u]; i; i = rg.ne[i]) {
			int v = rg.to[i];
			if (dis[v] > dis[u] + rg.w[i] + eps) {
				dis[v] = dis[u] + rg.w[i];
				pq.push(mp(-dis[v], v));
			}
		}
	}
}


void dfs(int u){
	st[++top] = u; vis[u] = 1;
	for (int i = rg.h[u]; i; i = rg.ne[i]) {
		int v = rg.to[i];
		if (!vis[v] && fabs(dis[v] - dis[u] - rg.w[i]) <= eps) {
			fa[v] = u; tree[i] = 1;
			dfs(v);
		}
	}
}

int rt[N];

namespace LT{
	int ls[M*B], rs[M*B], ht[M*B], id[M*B];
	db val[M*B];
	int tot;
	inline int newnode(db _val, int _id, int _dis = 0){
		int p = ++tot;
		val[p] = _val, id[p]=_id, ht[p] = _dis;
		ls[p] = rs[p] = 0;
		return p;
	}
	
	inline int _copy(int ori){
		int p = ++tot;
		val[p] = val[ori], id[p] = id[ori], ht[p] = ht[ori];
		ls[p] = ls[ori], rs[p] = rs[ori];
		return p;
	}
	
	inline int merge(int a, int b){
		if(!a || !b) return a|b;
		if(val[a] > val[b]) swap(a, b);
		int now = _copy(a);
		rs[now] = merge(rs[now], b);
		if(ht[ls[now]] < ht[rs[now]]) swap(ls[now],rs[now]);
		ht[now] = ht[rs[now]] + 1;
		return now;
	}
	
	inline void ins(int &rt, db val, int id){
		rt = merge(rt, newnode(val, id));
	}
}

void build_heap(){
	rep(j, 1, top+1) {
		int u = st[j];
		rt[u] = rt[fa[u]];
		for (int i = g.h[u]; i ; i = g.ne[i]) {
			int v = g.to[i];
			if (!tree[i] && dis[v] < inf) LT::ins(rt[u], dis[v] - dis[u] + g.w[i], v);
		}
	}
}

typedef pair<db, int> pdi;

db E;

inline int calc_K(){
	int ans = 1; E -= dis[S];
	priority_queue<pdi, vector<pdi>, greater<pdi> > pq;
	if (rt[S]) pq.push(mp(dis[S] + LT::val[rt[S]], rt[S]));
	while(!pq.empty()) {
		pdi t = pq.top(); pq.pop();
		db w = t.fi; int u = t.se, o = LT::id[u];
		E -= w; if (E >= 0) ++ans; else return ans;
		int ls = LT::ls[u], rs = LT::rs[u];
		if (rt[o]) pq.push(mp(w + LT::val[rt[o]], rt[o]));
		if (ls) pq.push(mp(w + LT::val[ls] - LT::val[u], ls));
		if (rs) pq.push(mp(w + LT::val[rs] - LT::val[u], rs));
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> E;
	S = 1; T = n;
	rep(i, 1, m+1) {
		cin >> u >> v >> w;
		g.add(u, v, w);
		rg.add(v, u, w);
	}
	Dij(); 
	rep(i, 1, n+1) vis[i] = 0;
	dfs(T);
	build_heap();
	cout << calc_K() << endl;
	return 0;
}
