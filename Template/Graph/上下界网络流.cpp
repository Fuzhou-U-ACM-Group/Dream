template<class T>
struct Dinic{
    const static int N = 10101 , M = N * 50;
    int s, t, n, h[N], cur[N], lv[N], q[N], e, ne[M], to[M], m, ss, tt, id[M];
    T cap[M], flow, use[M], need, a[N];
    void liu(int u,int v,T w){ to[e] = v;ne[e] = h[u];cap[e] = w;h[u] = e++;}
    void link(int u,int v,T w){ liu(u, v, w);liu(v, u, 0);}
    void ini(int _n = N) { fill(h, h + (n=_n), -1); fill(a, a + n, 0); e = m = need = 0;}
    bool bfs(){
        int L = 0 , R = 0;
        fill(lv , lv + n , -1);
        lv[q[R++] = s] = 0;
        while(L < R && !~lv[t]){
            int c = q[L++];
            for(int k = h[c]; ~k ; k = ne[k])
                if(cap[k] > 0 && !~lv[to[k]]) 
                    lv[q[R++] = to[k]] = lv[c] + 1;
        }
        return ~lv[t];
    }
    T dfs(int c,T mx){
        if(c == t) return mx;
        T ret = 0;
        for(int &k = cur[c]; ~k; k = ne[k]){
            if(lv[to[k]] == lv[c] + 1 && cap[k] > 0){
                T flow = dfs(to[k] , min(mx , cap[k]));
                ret += flow;cap[k] -= flow , cap[k^1] += flow;mx -= flow;
                if(!mx) return ret;
            }
        }
        lv[c] = -1;
        return ret;
    }
    T run(int _s,int _t){
        s = _s , t = _t;
        flow = 0;
        while(bfs()){
            copy(h , h + n , cur);
            flow += dfs(s, ~0U>>1);
        }
        return flow;
    }
    
    void link(int u, int v, T wl, T wr) { // wl <= wr
		a[u] -= wl; a[v] += wl;
		use[++m] = wl; id[m] = e + 1;
		link(u, v, wr - wl);
	}
	void build() {
		ss = n - 2; tt = ss + 1;
		rep(i, 0, n) if (a[i] < 0) link(i, tt, -a[i]); else link(ss, i, a[i]), need += a[i]; 
	} 
	/*  o = 0 无源汇可行流  	
		o = 1 有源汇最大流
		o = -1 有源汇最小流 
		la 有源汇额外增加的 t->s 的边编号 
	*/
	int run(int o) { 
		build();
		T flow = run(ss, tt); 
		if (flow != need) return -1;
		if (o != 0) {
			flow = cap[::la ^ 1];
			cap[::la] = cap[::la ^ 1] = 0;
			if (o == 1) flow += run(:: s, :: t);
			else flow -= run(::t, ::s);
		}	
		rep(i, 1, m+1) use[i] += cap[id[i]];
		return flow;
	}
};
