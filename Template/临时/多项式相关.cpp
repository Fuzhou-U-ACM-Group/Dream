#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define fi first
#define se second
#define fe first
#define FI(x) freopen(#x".in","r",stdin)
#define FO(x) freopen(#x".out","w",stdout)
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;

const int P=998244353;
#define SZ 666666
ll w[2][SZ],rev[SZ];
inline ll qp(ll a,ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=ans*a%P;
		a=a*a%P;
		b>>=1;
	}
	return ans;
}
int K;
inline void fftinit(int n) {
	for(K=1; K<n; K<<=1);
	w[0][0]=w[0][K]=1;
	ll g=qp(3,(P-1)/K);
	for(int i=1; i<K; i++) w[0][i]=w[0][i-1]*g%P;
	for(int i=0; i<=K; i++) w[1][i]=w[0][K-i];
}
inline void fft(int* x,int v) {
	for(int i=0; i<K; i++) x[i]=(x[i]%P+P)%P;
	for(int i=0,j=0; i<K; i++) {
		if(i>j) swap(x[i],x[j]);
		for(int l=K>>1; (j^=l)<l; l>>=1);
	}
	for(int i=2; i<=K; i<<=1)
		for(int l=0; l<i>>1; l++) {
			register int W=w[v][K/i*l],*p=x+l+(i>>1),*q=x+l,t;
			for(register int j=0; j<K; j+=i) {
				p[j]=(q[j]-(t=(ll)p[j]*W%P)<0)?(q[j]-t+P):(q[j]-t);
				q[j]=(q[j]+t-P>=0)?(q[j]+t-P):(q[j]+t);
			}
		}
	if(!v) return;
	ll rv=qp(K,P-2);
	for(int i=0; i<K; i++) x[i]=x[i]*rv%P;
}
struct poly {
	vector<int> ps;
	inline int cs() {
		return ps.size()-1;
	}
	inline int& operator [] (int x) {
		return ps[x];   //ps.at(x)
	}
	inline void sc(int x) {
		ps.resize(x+1);
	}
	inline void dbg() {
		bool fi=0;
		for(int i=cs(); i>=0; i--) {
			ps[i]=(ps[i]%P+P)%P;
			if(!ps[i]) continue;
			if(ps[i]>P/2) ps[i]-=P;
			if(fi) {
				if(i==0) printf("%+d",ps[i]);
				else if(ps[i]==1) printf("+");
				else if(ps[i]==-1) printf("-");
				else printf("%+d",ps[i]);
			} else {
				if(i==0) printf("%d",ps[i]);
				else if(ps[i]==1);
				else if(ps[i]==-1) printf("-");
				else printf("%d",ps[i]);
			}
			if(i>1) printf("x^%d",i);
			else if(i==1) printf("x");
			fi=1;
		}
		if(!fi) printf("0");
		putchar(10);
	}
	inline void clr() {
		int p=cs()+1;
		while(p&&!ps[p-1]) --p;
		sc(p-1);
	}
};
namespace PolyMul { int ta[SZ], tb[SZ], tc[SZ];}
inline poly operator * (poly a, poly b) {
	using namespace PolyMul;
	if(a.cs()<180||b.cs()<180) {
		poly g;
		g.sc(a.cs()+b.cs());
		int*G=&g[0],*A=&a[0],*B=&b[0];
		for(int i=0; i<=a.cs(); i++) {
			register int*h=G+i,j=0;
			register ll x=A[i];
			for(; j<=b.cs(); ++j) h[j]=(h[j]+x*(ll)B[j])%P;
		}
		return g;
	}
	poly c;
	int t=a.cs()+b.cs();
	c.sc(t);
	fftinit(t+1);
	memset(ta,0,sizeof(int)*K);
	memset(tb,0,sizeof(int)*K);
	memset(tc,0,sizeof(int)*K);
	for(int i=a.cs(); i>=0; i--) ta[i]=a[i];
	for(int i=b.cs(); i>=0; i--) tb[i]=b[i];
	fft(ta,0);
	fft(tb,0);
	for(int i=0; i<K; i++) tc[i]=(ll)ta[i]*tb[i]%P;
	fft(tc,1);
	for(int i=t; i>=0; i--) c[i]=tc[i];
	c.clr();
	return c;
}
namespace PolyInv {
	int ay[SZ],a0[SZ],tmp[SZ];
}
inline void ginv(int t) {
	using namespace PolyInv;
	if(t==1) {
		a0[0]=qp(ay[0],P-2);
		return;
	}
	ginv((t+1)>>1);
	fftinit(t+t+3);
	memset(tmp,0,sizeof(int)*K);
	for(int i=t; i<K; i++) tmp[i]=a0[i]=0;
	for(int i=0; i<t; i++) tmp[i]=ay[i];
	fft(tmp,0);
	fft(a0,0);
	for(int i=0; i<K; i++) a0[i]=(2-(ll)tmp[i]*a0[i])%P*a0[i]%P;
	fft(a0,1);
	for(int i=t; i<K; i++) a0[i]=0;
}
inline poly inv(poly x) {
	using namespace PolyInv;
	poly y;
	y.sc(x.cs());
	for(int i=x.cs(); i>=0; i--) ay[i]=x[i];
	ginv(x.cs()+1);
	for(int i=x.cs(); i>=0; i--) y[i]=a0[i];
	y.clr();
	return y;
}
inline poly operator + (poly a,poly b) {
	poly w;
	w.sc(max(a.cs(),b.cs()));
	for(int i=a.cs(); i>=0; i--) w[i]=a[i];
	for(int i=b.cs(); i>=0; i--) (w[i]+=b[i])%=P;
	return w;
}
inline poly operator - (poly a,poly b) {
	poly w;
	w.sc(max(a.cs(),b.cs()));
	for(int i=a.cs(); i>=0; i--) w[i]=a[i];
	for(int i=b.cs(); i>=0; i--) (w[i]-=b[i])%=P;
	w.clr();
	return w;
}
inline void div(poly a,poly b,poly& d,poly& r) {
	int n=a.cs(),m=b.cs();
	if(n<m) {
		d.sc(0);
		d[0]=0;
		r=a;
		return;
	}
	fftinit(2*n);
	poly aa=a;
	reverse(aa.ps.begin(),aa.ps.end());
	poly bb=b;
	reverse(bb.ps.begin(),bb.ps.end());
	bb.sc(n-m);
	bb=inv(bb);
	d=aa*bb;
	d.sc(n-m);
	reverse(d.ps.begin(),d.ps.end());
	r=a-b*d;
	r.clr();
}
inline poly operator / (poly a,poly b) {
	poly d,r;
	div(a,b,d,r);
	return d;
}
inline poly operator % (poly a,poly b) {
	a.clr();
	b.clr();
	if(a.cs()<b.cs()) return a;
	poly d,r;
	div(a,b,d,r);
	return r;
}
inline poly dev(poly x) {
	for(int i=1; i<=x.cs(); i++) x[i-1]=(ll)x[i]*i%P;
	x.sc(x.cs()-1);
	return x;
}
inline poly inte(poly x) {
	x.sc(x.cs()+1);
	for(int i=x.cs(); i>=1; i--) x[i]=x[i-1];
	x[0]=0;
	for(int i=x.cs(); i>=1; i--) x[i]=(ll)x[i]*rev[i]%P;
	return x;
}
inline ll qz(poly& a,ll x) {
	ll ans=0;
	for(int i=a.cs(); i>=0; i--) ans=(ans*x+a[i])%P;
	return ans;
}
poly vvs[SZ];
inline void gvs(int m,int* x,int id) {
	if(m==1) {
		vvs[id].sc(1), vvs[id][1]=1, vvs[id][0]=-*x;
		return;
	}
	int hf=m>>1;
	gvs(hf,x,id*2);
	gvs(m-hf,x+hf,id*2+1);
	vvs[id]=vvs[id*2]*vvs[id*2+1];
}
namespace PolyGetv {
	int xs[SZ],anss[SZ];
};
inline void gv(poly f,int m,int* x,int* ans,int id) {
	if(f.cs()<=1000) {
		int c=f.cs(),*F=&f.ps[0];
		for(int i=0; i<m; i++) {
			register ll t=0;
			register int v=x[i];
			for(register int j=c; ~j; --j) t=(t*v+F[j])%P;
			ans[i]=t;
		}
		return;
	}
	int hf=m>>1;
	gv(f%vvs[id*2],hf,x,ans,id*2);
	gv(f%vvs[id*2+1],m-hf,x+hf,ans+hf,id*2+1);
}
inline vector<int> getv(poly a,vector<int> x) {
	using namespace PolyGetv;
	a.clr();
	if(!x.size()) return vector<int>();
	int m=x.size();
	for(int i=0; i<m; i++) xs[i]=x[i];
	gvs(m,xs,1);
	gv(a%vvs[1],m,xs,anss,1);
	vector<int> ans;
	ans.resize(m);
	for(int i=0; i<m; i++) ans[i]=anss[i];
	return ans;
}
namespace PolyIntp {
	int xs[SZ],vs[SZ];
};
inline poly comb(int m,int*v,int id) {
	if(m==1) {
		poly s;
		s.sc(0);
		s[0]=*v;
		return s;
	}
	int hf=m>>1;
	return comb(hf,v,id*2)*vvs[id*2+1]
	       +comb(m-hf,v+hf,id*2+1)*vvs[id*2];
}
inline poly intp(vector<int> x,vector<int> y) {
	using namespace PolyIntp;
	int m=x.size();
	for(int i=0; i<m; i++) xs[i]=x[i];
	gvs(m,xs,1);
	gv(dev(vvs[1]),m,xs,vs,1);
	for(int i=0; i<m; i++)
		vs[i]=y[i]*qp(vs[i],P-2)%P;
	return comb(m,vs,1);
}

int n, m, x, y;

int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	rev[1]=1;
	for(int i=2; i<SZ; ++i) rev[i]=-rev[P%i]*(ll)(P/i)%P;
	cin >> n;
	vi xx, yy, zz;
	/*for(int i=0,x,y;i<n;++i) {
	    cin >> x >> y;
		xx.pb(x),yy.pb(y);
	}
	poly g = intp(xx, yy);
	g.dbg(); */
	poly g;
	g.sc(n);
	rep(i, 0, n+1) cin >> x, g[i] = x;
	
	for(int i = 0, z; i < m; ++i) cin >> z, zz.pb(z);
	vector<int> vs = getv(g, zz);
	for(int i=0; i<m; ++i)
		cout << ((vs[i]%P+P)%P) << "\n";
}
