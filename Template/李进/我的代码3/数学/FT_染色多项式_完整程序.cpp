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

#define ____ puts("\n_______________\n\n") 
#define debug(x) ____; cout<< #x << " => " << (x) << endl
#define debug_pair(x) cout<<"\n{ "<<(x).fir<<" , "<<(x).sec<<" }\n"
#define debug_arr(x,n) ____; cout<<#x<<":\n"; rep(i,0,n+1) cout<<#x<<"["<<(i)<<"] => "<<x[i]<<endl
#define debug_arr2(x,n,m) ____; cout<<#x<<":\n"; rep(i,0,n+1) rep(j,0,m+1) cout<<#x<<"["<<(i)<<"]["<<(j)<<"]= "<<x[i][j]<<((j==m)?"\n\n":"    ")
#define debug_set(x) ____; cout<<#x<<": \n"; rep_it(it,x) cout<<(*it)<<" "; cout<<endl
#define debug_map(x) ____; cout<<#x<<": \n"; rep_it(it,x) debug_pair(*it)

void file_put() {
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
}

template<class T>
struct Poly{
	static const int N = 30, P = 1e9+7;
	T a1[N], b1[N], c[N];
	T add(T a, T b) {a = (a + b) % P; return a < 0 ? a + P : a;}
	T mul(T a, T b) {a = 1ll * a * b % P; return a < 0 ? a + P : a;}
	T kpow(T a, T b) {T r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
	void calc(int n, T *a, T *b) {
		fill_n(c, n+1, 0);
		rep(i, 0, n+1)	rep(j, 0, 2) c[i+j] = add(c[i+j], mul(a[i], b[j]));
		memcpy(a, c, sizeof(a[0]) * (n+1));
	} 
	void solve(int n, T *x, T *y, T *a){ // a[0]*x^0 ... a[n]*x^n
		fill_n(a, n+1, 0);
		rep(i, 0, n+1) {
			fill_n(a1, n+1, 0); a1[0] = 1;
			rep(j, 0, n+1) if (j != i) a1[0] = mul(a1[0], x[i] - x[j]);
			a1[0] = mul(y[i], kpow(a1[0], P - 2));
			rep(j, 0, n+1) if (j != i) {
				b1[0] = -x[j]; b1[1] = 1;
				calc(n, a1, b1);
			}
			rep(j, 0, n+1) a[j] = add(a[j], a1[j]);
		}
	}
};

const int P = 1e9 + 7, M = 15;
inline int mul(int x, int y) { return (ll)x*y%P; }
inline int add(int x, int y) { return (x += y) >= P ? x - P : x; }

template <int L>
struct Num {
	array<int, L> a;
	inline int& operator [] (int x) { return a[x]; }
	inline int operator [] (int x) const { return a[x]; }
	inline void clear() { a.fill(0); }
	inline void operator += (const Num &b) {
		rep(i, 0, L) a[i] = add(a[i], b[i]);
	}
	inline void operator -= (const Num &b) {
		rep(i, 0, L) a[i] = add(a[i], P - b[i]);
	}
	inline friend Num operator * (const Num &a, const Num &b) {
		Num<L> c; c.clear();
		rep(i, 0, L) if (a[i])
			for (int j = 0; i + j < L; ++j) if (b[j])
				c[i + j] = add(c[i + j], mul(a[i], b[j]));
		return c;
	}
};

template <class V>
struct Calculator {
	V aa[1 << M], bb[1 << M];
	void fwt(V a[], int len, int o = 1) {  // o=-1 UFWT
		for (int k = 0; 1 << k < len; ++k)
			rep(i, 0, len) if (~i >> k & 1) {
			int j = i ^ (1 << k);
			(o == 1) ? a[j] += a[i] : a[j] -= a[i];
		}
	}
	int get(V a[], int len, int s) {
	    int ret=0,k=__builtin_popcount(s);
	    rep(t,0,s+1) if ((t&s)==t)
	        if (__builtin_parity(s^t)) ret=add(ret,P-a[t][k]); else ret=add(ret,a[t][k]);
        return ret;
    }
	void pow(V a[], int len, int k, V c[], int ret[]) {
		fwt(a, len),ret[0]=0;
		rep(i, 0, len) c[i] = a[i];
		ret[1]=get(c,len,len-1);
		rep(j, 2, k + 1) {
		    rep(i,0,len) c[i] = c[i] * a[i];
		    ret[j]=get(c,len,len-1);
        }
	}
	void In(int A[], int len, V a[]) {
		rep(i, 0, len) a[i].clear(), a[i][__builtin_popcount(i)] = A[i];
	}
	void Pow(int A[], int len, int k, int C[]) {
		In(A, len, aa), pow(aa, len, k, bb, C);
	}
	void ModP(int a[], int len) {
		rep(i, 0, len) a[i] = add(a[i], P);
	}
};

Calculator<Num<M + 1>> T;
Poly<int> PP; int X[30],Y[30];
void Solve(int a[],int n,int mask[],int color[],int ret[]) {
    mask[0]=1; int L=1<<M;
    rep(s,1,L) {
        int t=s&-s,k=__builtin_ctz(t);
        mask[s]=(mask[s^t] && !(s&a[k]));
    }
    T.Pow(mask,L,n,color);
    rep(i,0,n+1) X[i]=i,Y[i]=color[i];
    PP.solve(n,X,Y,ret);
}

// random and check 

mt19937 gen(time(0));
typedef uniform_int_distribution<ll> RR;
ll rnd(ll l, ll r) { RR dis(l, r); return dis(gen); }

void Rand_a(int a[],int n) {
    int all=(1<<n)-1;
    rep(i,0,n) a[i]=rnd(0,all);
    rep(i,0,n) a[i]&=all^(1<<i);
    rep(i,0,n) rep(j,0,n)
        if (a[i]>>j&1) a[j]|=1<<i; else a[j]&=all^(1<<i);
}

void Print_a(int a[],int n) {
    printf("Graph: adj \n");
    int m=0;
    rep(i,0,n) {
        bitset<M> B(a[i]);
        m+=B.count();
        rep(j,0,n) printf("%d",(int)B[j]);
        printf("\n");
    }
    m>>=1;
    printf("\n");
    printf("Graph: link \n");
    printf("%d %d\n",n,m);
    rep(x,0,n) rep(y,0,x) {
        if (a[x]>>y&1) printf("%d %d\n",y,x);
    }
}

bool Check_mask(int a[],int n,int mask[]) {
    int L=1<<M;
    rep(s,0,L) {
        bool ok=1;
        rep(x,0,M) rep(y,0,M) {
            if (x==y || s>>x&1^1 || s>>y&1^1) continue;
            ok&=a[x]>>y&1^1;
        }
        if (mask[s]!=ok) return 0;
    }
    return 1;
}

int g[1<<M],mask[1<<M],color[M+5],ret[M+5];
int _color[M+5],cnt;

int get(int a[],int n,int x) {
    int ans=0,t=1;
    rep(i,0,n+1) ans=add(ans,mul(t,a[i])),t=mul(t,x);
    return ans;
}

int w[M+5],n;


bool check_indep(int w[],int n) {
    rep(x,0,n) rep(y,0,x) {
        if (g[x]>>y&1) {
            if (w[x]==w[y]) return 0;
        }
    }
    return 1;
}

void dfs(int k,int K) {
    if (k>=n) {
        cnt+=check_indep(w,n);
        return;
    }
    rep(c,1,K+1) {
        w[k]=c;
        dfs(k+1,K);
    }
}

bool Check_color(int color[],int ret[],int n) {
    int c[M+5],dd[M+5]; dd[0]=0;
    rep(x,0,n+1) c[x]=get(ret,n,x);
    rep(K,1,n+1) {
        fill(w+0,w+n,0);
        cnt=0;
        dfs(0,K);
        dd[K]=cnt;
//        if (color[K]!=cnt || c[K]!=cnt) return 0;
    } 
    debug_arr(c,M);
    debug_arr(dd,M);
    rep(K,0,n+1) if (color[K]!=dd[K] || c[K]!=dd[K]) return 0;
    return 1;
}

int main() {
    file_put();
    
    n=M;
    Rand_a(g,M);
    Solve(g,M,mask,color,ret);
//    debug_arr(g,M-1);
    Print_a(g,M); 
    debug_arr(mask,(1<<M)-1);
//    if (Check_mask(g,M,mask)) printf("Yes : mask\n"); else printf("No : mask\n");

    debug_arr(color,M);
    debug_arr(ret,M);
    

//    if (Check_color(color,ret,n)) printf("Yes : color\n"); else printf("No : color\n");
    
	return 0;
}

/*

Graph: link 
5 6
0 2
1 3
0 4
1 4
2 4
3 4

Color Ways
{ 0, 0, 0, 12, 144, 720 } 

Chromatic Poly
x (x - 1)^2 (x - 2)^2 = {0, 4, -12, 13, -6, 1}


Graph: link 
6 9
0 1
1 2
0 3
1 3
2 3
2 4
3 4
0 5
3 5

Color Ways
{ 0, 0, 0, 6, 192, 1620, 7680 } 

Chromatic Poly
{0, -16, 48, -56, 32, -9, 1}

*/


