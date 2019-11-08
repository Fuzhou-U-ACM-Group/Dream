#include<bits/stdc++.h>
using namespace std;
const int maxn=211;
 
struct MI;
MI power(MI x,int t);
struct MI{
	const static int p=1000000007;
	MI():v(0){}
	MI(int v):v(v){
		while (v>=p) v-=p;
		while (v<0) v+=p;
	}
	MI(const MI&a):v(a.v){}
	MI& operator +=(const MI &b){
		v+=b.v;
		while (v>=p) v-=p;
		while (v<0) v+=p;
		return *this;
	}
	MI& operator -=(const MI &b){
		v-=b.v;
		while (v>=p) v-=p;
		while (v<0) v+=p;
		return *this;
	}
	MI& operator *=(const MI &b){
		v=1LL*v*b.v%p;
		if (v<0) v+=p;
		return *this;
	}
	static MI inv(const MI &x){
		return power(x,p-2);
	}
	MI& operator /=(const MI &b){
		return *this*=inv(b);
	}
	int v;
	
};
MI operator +(const MI &a,const MI &b){
	MI c=a;
	return c+=b;
}
MI operator -(const MI &a,const MI &b){
	MI c=a;
	return c-=b;
}
MI operator *(const MI &a,const MI &b){
	MI c=a;
	return c*=b;
}
MI operator /(const MI &a,const MI &b){
	MI c=a;
	return c/=b;
}
 
MI power(MI x,int t){
	MI res=1;
	for (;t;t>>=1,x*=x)
		if (t&1) res*=x;
	return res;
}
 
struct Teq{
	vector<MI> a;
	MI& operator[](int idx){
		return a[idx];
	}
	const MI operator[](int idx)const{
		return a[idx];
	}
	Teq& operator +=(const MI &b){
		a.back()+=b;
		return *this;
	}
	Teq& operator -=(const MI &b){
		a.back()-=b;
		return *this;
	}
	Teq& operator +=(const Teq &b){
		assert(a.size()==b.a.size());
		for (int i=0;i<(int)a.size();++i) a[i]+=b[i];
		return *this;
	}
	Teq& operator -=(const Teq &b){
		assert(a.size()==b.a.size());
		for (int i=0;i<(int)a.size();++i) a[i]-=b[i];
		return *this;
	}
	Teq& operator *=(const MI &x){
		for (auto &t:a) t*=x;
		return *this;
	}
	Teq& operator /=(const MI &x){
		return *this*=MI::inv(x);
	}
	void clear(int n_){
		a.clear();
		a.resize(n_);
	}
	void print()const{
		cerr<<"{";
		for (int i=0;i<(int)a.size();++i)
			cerr<<a[i].v<<", ";
		cerr<<"}"<<endl;
	}
};
Teq operator +(const Teq &a,const MI &b){
	Teq c=a;
	return c+=b;
}
Teq operator -(const Teq &a,const MI &b){
	Teq c=a;
	return c-=b;
}
Teq operator +(const Teq &a,const Teq &b){
	Teq c=a;
	return c+=b;
}
Teq operator -(const Teq &a,const Teq &b){
	Teq c=a;
	return c-=b;
}
Teq operator *(const Teq &a,const MI &b){
	Teq c=a;
	return c*=b;
}
Teq operator /(const Teq &a,const MI &b){
	Teq c=a;
	return c/=b;
}
MI operator *(const Teq &a,const Teq &b){
	assert(a.a.size()==b.a.size());
	MI res=0;
	for (int i=0;i<(int)a.a.size();++i)
		res+=a[i]*b[i];
	return res;
}
 
int n,m;
bool hole[maxn][maxn];
int id[maxn][maxn],stx,sty;
Teq expr[maxn][maxn];
vector<Teq>eqs;
MI A[maxn][maxn],B[maxn][maxn];
 
Teq gauss(vector<Teq> &eqs){
//	cerr<<"In"<<endl;
//	for (auto x:eqs) x.print();
	vector<Teq> tmp=eqs;
	assert(eqs.size());
	int n=eqs[0].a.size(),m=eqs.size();
	assert(m>=n-1);
	for (int i=0;i+1<n;++i){
		int id=-1;
		for (int j=i;j<m;++j) if (eqs[j][i].v){id=j; break;}
		assert(id!=-1);
		if (id!=i) swap(eqs[i],eqs[id]);
		for (int j=i+1;j<m;++j)
			eqs[j]-=eqs[i]*(eqs[j][i]/eqs[i][i]);
	}
	
	
	Teq ans; ans.clear(n); ans.a.back()=1;
	
	
	for (int i=n-2;i>=0;--i)
		ans[i]=(eqs[i]*ans)/(0-eqs[i][i]);
//	cerr<<"Out"<<endl;
	
	
	return ans;
}
 
const int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
 
inline int D(int x,int y){
	return 4-(x==1)-(x==n)-(y==1)-(y==n);
}
 
int main(){
	freopen("a.in", "r", stdin); 
	int T; scanf("%d",&T);
	while (T--){
		static int X[maxn],Y[maxn];
		scanf("%d%d",&n,&m);
		for (int i=0;i<=n+1;++i) for (int j=0;j<=n+1;++j) hole[i][j]=!(i>=1 && i<=n && j>=1 && j<=n);
		for (int i=1;i<=m;++i) scanf("%d%d",X+i,Y+i),hole[X[i]][Y[i]]=1;
		scanf("%d%d",&stx,&sty);
		int N=0;
		for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) id[i][j]=-1;
		for (int j=1;j<=n;++j) if (!hole[1][j]) id[1][j]=N++;
		
		for (int i=2;i<=n;++i) for (int j=1;j<=n;++j)
			if (hole[i-1][j] && !hole[i][j]) id[i][j]=N++;
			
//		for (int i=1;i<=n;++i) for (int j=1;j<=n;++j)
//			cerr<<i<<' '<<j<<' '<<id[i][j]<<endl;
			
		eqs.clear();
		for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) if (!hole[i][j] && id[i][j]!=-1){
			expr[i][j].clear(N+1);
			expr[i][j][id[i][j]]=1;
		}
		for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) if (!hole[i][j]){
			if (hole[i+1][j]){
				Teq eq; eq=expr[i][j];
				if (i==stx && j==sty) eq[N]-=1;
				if (!hole[i-1][j]) eq-=expr[i-1][j]/D(i-1,j);
				if (!hole[i][j-1]) eq-=expr[i][j-1]/D(i,j-1);
				if (!hole[i][j+1]) eq-=expr[i][j+1]/D(i,j+1);
				eqs.emplace_back(eq);
			}else{ // 下方不是洞 
				Teq &eq=expr[i+1][j]; eq=expr[i][j];
				if (i==stx && j==sty) eq[N]-=1;
				if (!hole[i-1][j]) eq-=expr[i-1][j]/D(i-1,j);
				if (!hole[i][j-1]) eq-=expr[i][j-1]/D(i,j-1);
				if (!hole[i][j+1]) eq-=expr[i][j+1]/D(i,j+1);
				eq*=D(i+1,j);
			}
		}
		
		assert((int)eqs.size()==N);
		
		Teq ans=gauss(eqs);
//		ans.print();
		
		for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) if (!hole[i][j])
			A[i][j]=expr[i][j]*ans;
		for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) if (hole[i][j]){
			A[i][j]=0;
			if (!hole[i-1][j]) A[i][j]+=A[i-1][j]/D(i-1,j);
			if (!hole[i+1][j]) A[i][j]+=A[i+1][j]/D(i+1,j);
			if (!hole[i][j-1]) A[i][j]+=A[i][j-1]/D(i,j-1);
			if (!hole[i][j+1]) A[i][j]+=A[i][j+1]/D(i,j+1);
		}
		
		
		
		
		eqs.clear();
		for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) if (!hole[i][j] && id[i][j]!=-1){
			expr[i][j].clear(N+1);
			expr[i][j][id[i][j]]=1;
		}
		for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) if (!hole[i][j]){
			if (hole[i+1][j]){
				Teq eq; eq=expr[i][j];
				if (!hole[i-1][j]) eq-=expr[i-1][j]/D(i-1,j),eq-=A[i-1][j]/D(i-1,j);
				if (!hole[i][j-1]) eq-=expr[i][j-1]/D(i,j-1),eq-=A[i][j-1]/D(i,j-1);
				if (!hole[i][j+1]) eq-=expr[i][j+1]/D(i,j+1),eq-=A[i][j+1]/D(i,j+1);
				eqs.emplace_back(eq);
			}else{
				Teq &eq=expr[i+1][j]; eq=expr[i][j];
				if (!hole[i-1][j]) eq-=expr[i-1][j]/D(i-1,j),eq-=A[i-1][j]/D(i-1,j);
				if (!hole[i][j-1]) eq-=expr[i][j-1]/D(i,j-1),eq-=A[i][j-1]/D(i,j-1);
				if (!hole[i][j+1]) eq-=expr[i][j+1]/D(i,j+1),eq-=A[i][j+1]/D(i,j+1);
				eq*=D(i+1,j); eq-=A[i+1][j];
			}
		}
		assert((int)eqs.size()==N);
		ans=gauss(eqs);
		for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) if (!hole[i][j])
			B[i][j]=expr[i][j]*ans;
		for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) if (hole[i][j]){
			B[i][j]=0;
			if (!hole[i-1][j]) B[i][j]+=(A[i-1][j]+B[i-1][j])/D(i-1,j);
			if (!hole[i+1][j]) B[i][j]+=(A[i+1][j]+B[i+1][j])/D(i+1,j);
			if (!hole[i][j-1]) B[i][j]+=(A[i][j-1]+B[i][j-1])/D(i,j-1);
			if (!hole[i][j+1]) B[i][j]+=(A[i][j+1]+B[i][j+1])/D(i,j+1);
		}
		
//		for (int i=1;i<=n;++i) for (int j=1;j<=n;++j)
//			cerr<<i<<' '<<j<<' '<<A[i][j].v<<' '<<B[i][j].v<<endl;
		/*		
		for (int i=1;i<=n;++i) for (int j=1;j<=n;++j){
			MI res=A[i][j];
			for (int d=0;d<4;++d) if (!hole[i+dx[d]][j+dy[d]])
				res-=A[i+dx[d]][j+dy[d]]/D(i+dx[d],j+dy[d]);
			cerr<<i<<' '<<j<<' '<<res.v<<endl;
			assert(res.v==0 || (i==stx && j==sty && res.v==1));
		}
	
		for (int i=1;i<=n;++i) for (int j=1;j<=n;++j){
			MI res=B[i][j]*4;
			for (int d=0;d<4;++d) if (!hole[i+dx[d]][j+dy[d]])
				res-=A[i+dx[d]][j+dy[d]]+B[i+dx[d]][j+dy[d]];
//			cerr<<i<<' '<<j<<' '<<res.v<<endl;
			assert(res.v==0);
		}
		*/
		
		for (int i=1;i<=m;++i) if (!A[X[i]][Y[i]].v)
			printf("GG%c",i==m?'\n':' ');
		else
			printf("%d%c",(B[X[i]][Y[i]]/A[X[i]][Y[i]]).v,i==m?'\n':' ');
			//printf("%d%c",A[X[i]][Y[i]].v,i==m?'\n':' ');
		printf("%d\n", B[3][2].v);
	}
}
