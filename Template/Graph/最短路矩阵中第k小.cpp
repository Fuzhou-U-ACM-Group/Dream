const int N = 2e5 + 7;
vector<pii> g[N]; // (边权, 终点) 需要排序 
int n, m, k, u, v, w;

struct data { // 距离 起点 当前点 当前扩展过的边编号 
    ll w; int st, last, id;
    data(ll W, int S, int L, int I) {
        w = W; st = S; last = L; id = I;
    }
    bool operator < (const data &c) const {
        return w > c.w;
    }
};

// 连通图的话 k <= n * (n - 1) 
// 复杂度最坏应该是 O( min(nmlogn, k^2logk) ) 正常应该是 O(klogk + nlogn) 
ll solve(int n, vector<pii> g[], int k) { 
	priority_queue<data> pq; 
    set<pii> vis;
    rep(i, 1, n+1) {
        if (sz(g[i])) pq.push(data(g[i][0].fi, i, i, 0));
        vis.insert(mp(i, i));
    }
    while (!pq.empty()) {
        data u = pq.top(); pq.pop();
        int v = g[u.last][u.id].se;
        if (!vis.count(mp(u.st, v))) {
            vis.insert(mp(u.st, v));
        	k--; if (k == 0) return u.w;
            if (sz(g[v])) pq.push(data(u.w + g[v][0].fi, u.st, v, 0));
        }
        if (u.id + 1 < sz(g[u.last])) 
            pq.push(data(u.w - g[u.last][u.id].fi + g[u.last][u.id + 1].fi, u.st, u.last, u.id + 1));
	}
} 

