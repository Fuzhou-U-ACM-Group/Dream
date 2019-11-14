namespace SchreierSims {
	typedef vi P;
	typedef vector<P> B;
	P inv(P p) {
		P r=p;
		rep(i,0,sz(p)) r[p[i]]=i;
		return r;
	}
	P operator * (const P&a,const P&b) {
		P r=a;
		rep(i,0,sz(a)) r[i]=b[a[i]];
		return r;
	}
	int n , m;
	vector<B> buckets , bucketsInv;
	vector<vi> lookupTable;
	int fastFilter(const P&g,bool addToGroup = true) {
		int n = sz(buckets);
		P p = g;
		rep(i,0,n) {
			int res=lookupTable[i][p[i]];
			if(res == -1) {
				if(addToGroup) {
					buckets[i].push_back(p);
					bucketsInv[i].pb(inv(p));
					lookupTable[i][p[i]] = sz(buckets[i]) - 1;
				}
				return i;
			}
			p = p * bucketsInv[i][res];
		}
		return -1;
	}
	// 计算置换群的阶
	ll cal() {
		ll res=1;
		rep(i,0,n) res*=sz(buckets[i]);
		return res;
	}
	// 判断置换是否在置换群中
	bool inGroup(const P&g) {
		return fastFilter(g , false) == -1;
	}
	// 置换群的生成集合，第二维是置换的长度
	void solve(const B&gen,int _n) {
		n = _n , m = sz(gen);
		bucketsInv=buckets=vector<B>(n);
		lookupTable=vector<vi>(n);
		P id(n);
		rep(i,0,n) {
			lookupTable[i].resize(n);
			fill(all(lookupTable[i]),-1);
		}
		rep(i,0,n) id[i]=i;
		rep(i,0,n) {
			buckets[i].pb(id);
			bucketsInv[i].pb(id);
			lookupTable[i][i]=0;
		}
		rep(i,0,m) fastFilter(gen[i]);
		queue<pair<pii,pii> > toUpdate;
		rep(i,0,n) rep(j,i,n) rep(k,0,sz(buckets[i])) rep(l,0,sz(buckets[j]))
		toUpdate.push(mp(mp(i,k),mp(j,l)));
		while(sz(toUpdate)) {
			pii a=toUpdate.front().fi , b=toUpdate.front().se;
			toUpdate.pop();
			int res=fastFilter(buckets[a.fi][a.se]*buckets[b.fi][b.se]);
			if(res==-1) continue;
			pii np(res,sz(buckets[res])-1);
			rep(i,0,n) rep(j,0,sz(buckets[i])) {
				if(i<=res) toUpdate.push(mp(mp(i,j),np));
				if(res<=i) toUpdate.push(mp(np,mp(i,j)));
			}
		}
	}
}
/*
2 5
2 1 3 4 5
2 3 4 5 1

120
*/