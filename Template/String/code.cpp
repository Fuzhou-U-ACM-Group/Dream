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

#define mem(a,x) memset(a,x,sizeof(a))
#define rep_it(it,x) for (__typeof((x).begin()) it=(x).begin(); it!=(x).end(); it++)
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

#define M 26
#define N 1000010
int l1[N],l2[N];
struct Palindromic_Tree{
    int next[N][M],fail[N],s[N];
    int cnt[N],kind[N],len[N];
    int last[2],p,L,R;
    void init(int n){
        p+=2;
        len[p-1]=-1;
        fail[0]=1;
        L=n,R=L-1;
        mem(s,-1);
    }
    int get_fail(int x,int k,int op){
    	op=2*op-1;
        while(s[k-op*(len[x]+1)]!=s[k])x=fail[x];
        return x;
    }
    void insert(int c,bool back){
        if(back)s[++R]=c-'a';
        else s[--L]=c-'a';
        int k=back==true? R:L;
        int cur=get_fail(last[back],k,back);
        if(!next[cur][c-'a']){
            int now=p++;
            len[now]=len[cur]+2;
            fail[now]=next[get_fail(fail[cur],k,back)][c-'a'];
            next[cur][c-'a']=now;
            kind[now]=kind[fail[now]]+1;
        }
        last[back]=next[cur][c-'a'];
        if(len[last[back]]==R-L+1)last[back^1]=last[back];
        cnt[last[back]]++;
    }
    void count(){
        for(int i=p-1;i>-1;i--)cnt[fail[i]]+=cnt[i];
    }
} T;

char s[N]; int n;

int main() {
	file_put();
	
	scanf("%s",s),n=strlen(s);
	T.init(n);
//	rep(i,n/2+1,n) T.insert(s[i],1);
//	per(i,0,n/2+1) T.insert(s[i],0);
//	rep(i,0,n) T.insert(s[i],1);
//	rep(i,0,n) T.insert(s[i],0);

	rep(i,1,n) T.insert(s[i],1);
	per(i,0,1) T.insert(s[i],0);
	debug(T.p-2);
	
	return 0;
}

