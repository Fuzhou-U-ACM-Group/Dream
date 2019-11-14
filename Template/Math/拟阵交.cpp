const int N = 5005;
int col[N], n, m, tot, tot2, k; ll val[N], x;
struct LM { // 线性拟阵 
    ll base[63];
    LM() { memset(base, 0, sizeof(base)); }
    void add(ll x) {
        per(j, 0, 63) if ((x >> j) & 1){
            if(!base[j]) {
                base[j] = x;
                break;
            } else x ^= base[j];
        	if (!x) break;
		}
    }
    bool test(ll x) {
        per(j, 0, 63) if ((x >> j) & 1){
            if(!base[j]) return 1; else x ^= base[j];
        	if (!x) break;
		}
        return 0;
    }
};
struct CM { // 高维均匀拟阵 
    int cnt[125];
    CM() { memset(cnt,0,sizeof(cnt)); }
    void add(int x) { cnt[x]++; }
    bool test(int x) { return cnt[x] == 0; }
};
template <class MT1, class MT2>
struct MI {
    int n, pre[N], id[N]; bool vis[N], sink[N], has[N]; queue<int> q;
    MI(int n) : n(n) {}
    void clear() {
    	rep(i, 1, n+1) vis[i] = sink[i] = pre[i] = 0;
        while (!q.empty()) q.pop();
    }
    vi getcur() {
        vi ret;
        rep(i, 1, n+1) if (has[i]) ret.pb(i), id[i] = sz(ret) - 1;
        return ret;
    }
    void push(int v, int p) { vis[v] = 1, pre[v] = p, q.push(v); }
    vi run() {
        MT1 mt1;  MT2 mt2;
        memset(has, 0, sizeof(has));
        while(1) {
            vi cur = getcur(); clear();
            MT1 mt1; MT2 mt2; 
            for(auto x : cur) mt1.add(val[x]), mt2.add(col[x]);
            rep(i, 1, n+1) if (!has[i]) {
                if(mt1.test(val[i])) push(i, 0); // X1;
                if(mt2.test(col[i])) sink[i] = 1; // X2;
            }
            bool ok = 0;
            rep(i, 1, n+1) if (sink[i] && vis[i]) { has[i] ^= 1; ok = 1; break;}
            if (ok) continue;
            
            vector<MT1> vmt1(sz(cur)); vector<MT2> vmt2(sz(cur));
            rep(i, 0, sz(cur))
            	rep(j, 0, sz(cur)) if (i != j) {
                    vmt1[i].add(val[cur[j]]);
                    vmt2[i].add(col[cur[j]]);
                }
            
            int t = -1;
            while(!q.empty()) {
                int u = q.front(); q.pop();
                if (sink[u]) { t = u; break;}
                rep(v, 1, n+1) if (!vis[v] && has[u] != has[v]){
                    if(has[u]) {
                        if(vmt1[id[u]].test(val[v])) push(v, u);
                    }
                    else {
                        if(vmt2[id[v]].test(col[u])) push(v, u);
                    }
                }
            }
            if (t == -1) return cur;
            while (t) has[t] ^= 1, t = pre[t]; 
        }
    }
};

//Pick Your Own Nim
//In real cases, Linear Matroid Need Optimization to Pass
int main() {
    cin >> n;
    rep(i, 0, n) cin >> x, val[++tot] = x, col[tot] = ++tot2;
    cin >> m;
    rep(i, 0, m) {
        cin >> k; tot2++;
        rep(j, 0, k) cin >> x, val[++tot] = x, col[tot] = tot2;
    }
    MI<LM, CM> matint(tot);
    vi res = matint.run();
    if (sz(res) < n + m)  cout << -1 << endl;
    else for(auto x : res) if (col[x] > n) cout << val[x] << endl;
    return 0;
}