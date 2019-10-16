#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

void file_put() {
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
}

#define ____ puts("\n_______________\n\n") 
#define debug(x) ____; cout<< #x << " => " << (x) << endl
#define debug_pair(x) cout<<"\n{ "<<(x).fir<<" , "<<(x).sec<<" }\n"
#define debug_arr(x,n) ____; cout<<#x<<":\n"; rep(i,0,n+1) cout<<#x<<"["<<(i)<<"] => "<<x[i]<<endl
#define debug_arr2(x,n,m) ____; cout<<#x<<":\n"; rep(i,0,n+1) rep(j,0,m+1) cout<<#x<<"["<<(i)<<"]["<<(j)<<"]= "<<x[i][j]<<((j==m)?"\n\n":"    ")
#define debug_set(x) ____; cout<<#x<<": \n"; rep_it(it,x) cout<<(*it)<<" "; cout<<endl
#define debug_map(x) ____; cout<<#x<<": \n"; rep_it(it,x) debug_pair(*it)

const int P = 1e9 + 7, M=18;
template <int L>
struct Num {
	array<int,L> a;
	inline int& operator [] (int x) { return a[x]; }
	inline int operator [] (int x) const { return a[x]; }
	inline void clear() { a.fill(0); }
    inline friend Num operator * (int k, const Num &b) {
        Num<L> c; rep(i,0,L) c[i]=(ll)k*b[i]%P; return c;
    }
    inline friend Num operator + (const Num &a,const Num &b) {
        Num<L> c; rep(i,0,L) c[i]=(a[i]+b[i])%P; return c;
    }
    inline friend Num operator * (const Num &a,const Num &b) {
        Num<L> c; c.clear(); rep(i,0,L) for (int j=0; i+j<L; ++j) c[i+j]+=(ll)a[i]*b[j]%P,c[i+j]%=P; return c;
    }
    inline void print() const { debug_arr(a,L-1); }
};

template <class V>
struct Calculator{
	V aa[1<<M],bb[1<<M];
    void fwt(V a[], int len, int o = 1) {  // o=-1 UFWT
    	for (int k = 0; 1 << k < len; ++k) 
            rep(i, 0, len) if (~i >> k & 1) {
        		int j = i ^ (1 << k);
                a[j] = a[j] + o * a[i];
    	   }
    }
    void mul(V a[],V b[],int len,V c[]) {
        fwt(a,len),fwt(b,len);
        rep(i,0,len) c[i]=a[i]*b[i];
        fwt(c,len,-1);
    }
    void pow(V a[],int len,int k,V c[]) {
        fwt(a,len);
        rep(i,0,len) {
            c[i]=a[i];
            rep(j,0,k-1) c[i]=c[i]*a[i];
        }
        fwt(c,len,-1);
    }
    void In(int A[],int len,V a[]) {
        rep(i,0,len) a[i].clear(),a[i][(int)__builtin_popcount(i)]=A[i];
    }
    void Out(V a[],int len,int A[]) {
        rep(i,0,len) A[i]=a[i][(int)__builtin_popcount(i)];
    }
    void Mul(int A[],int B[],int len,int C[]) {
        In(A,len,aa),In(B,len,bb),mul(aa,bb,len,aa),Out(aa,len,C);
    }
    void Pow(int A[],int len,int k,int C[]) {
        In(A,len,aa),pow(aa,len,k,bb),Out(bb,len,C);
    }
    void ModP(int a[],int len) {
        rep(i,0,len) a[i]=(a[i]+P)%P;
    }
    void print(V a[],int len) const {
    	printf("This is a list of array: \n");
    	rep(i,0,len) {
    		printf("array %d\n",i);
			a[i].print();
		}
		printf("\n\n");
	}
};

Calculator<Num<M+1>> T;

mt19937 gen(time(0));
typedef uniform_int_distribution<ll> RR;
ll rnd(ll l, ll r) { RR dis(l, r); return dis(gen); }

void Rand(int a[],int len) {
    rep(i,0,len) a[i]=rnd(0,P-1);
}

int a[1<<M],b[1<<M],c[1<<M],ret[1<<M],ans[1<<M],len=1<<M;

void B(int A[],int B[],int len,int C[]) {
    rep(x,0,len) rep(y,0,len) if (!(x&y)) C[x|y]+=(ll)A[x]*B[y]%P,C[x|y]%=P;
}

bool check(int a[],int b[],int len) {
    rep(i,0,len) if (a[i]!=b[i]) {
    	printf("error: %d\n",i);
    	return 0;
	}
    return 1;
}

//const Num<10> nn;

int main() {
    file_put();
    
    //Rand(a,len),Rand(b,len),Rand(c,len);
//    debug_arr(a,len-1); debug_arr(b,len-1);
    
    T.Mul(a,b,len,ret);
//	B(a,b,len,ans);
    
//    T.ModP(ret,len),T.ModP(ans,len);
    
//    debug_arr(ret,len-1);
//    debug_arr(ans,len-1); 
    
//    if (check(ret,ans,len)) printf("Yes\n"); else printf("No\n");
    
	return 0;
}

