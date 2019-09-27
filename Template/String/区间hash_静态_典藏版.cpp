struct STR{
	ll _B[N],h[N],base,P;
	inline void init_h(char st[],int n,ll _base=163,ll _P=1e9+7,char c='a'){
		base=_base,P=_P,h[0]=st[0]-c;
		rep(i,1,n) h[i]=(h[i-1]*base+st[i]-c)%P;
		if (_B[0]==1) return; _B[0]=1;
		rep(i,1,N) _B[i]=_B[i-1]*base %P;
	}
	inline ll H(int l,int r) {
		if (!l) return h[r]<0 ? h[r]+P : h[r];
		ll ans=(h[r]-h[l-1]*_B[r-l+1])%P;
		return ans<0 ? ans+P:ans;
	}
};
