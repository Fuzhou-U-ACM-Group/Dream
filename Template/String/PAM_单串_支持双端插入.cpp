const int M=26;
struct PAM{
	int ss[2*N],*s,len[N],next[N][M],fail[N],cnt[N],dep[N],id[N],no[N],last[2],n[2],p,cur,now,t; ll sum_cnt,ans;
	inline int new_node(int _l) { mem(next[p],0); cnt[p]=dep[p]=0,len[p]=_l; return p++; }
	inline void Init() { s=ss+N; new_node(p=0),new_node(s[0]=s[1]=-1),fail[last[0]=last[1]=n[1]=0]=n[0]=1; /*...*/ sum_cnt=0; }
	inline int get_fail(int x,int op) { int t=op*2-1; for (; s[n[op]-t*(len[x]+1)]!=s[n[op]]; x=fail[x]); return x; }
	inline void I(int c,int op) { 
		c-='a',t=op*2-1,s[n[op]+=t]=c,s[n[op]+t]=-1,cur=get_fail(last[op],op);
		if (!next[cur][c]) {
			now=new_node(len[cur]+2);
			fail[now]=next[get_fail(fail[cur],op)][c];
			next[cur][c]=now;
			dep[now]=dep[fail[now]]+1; //...
		}
		last[op]=next[cur][c],cnt[last[op]]++;
		if (len[last[op]]==n[1]-n[0]+1) last[op^1]=last[op];
		id[n[op]]=last[op]; no[last[op]]=n[op]+(len[last[op]]-1)*!op; //...
		sum_cnt+=dep[last[op]];
	}
	inline void Insert(char s[],int back=1,int op=0,int _n=0) { 
		if (!_n) _n=strlen(s);  if (!op) rep(i,0,_n) I(s[i],back); else per(i,0,_n) I(s[i],back); 
	}
	inline void count() { per(i,0,p) cnt[fail[i]]+=cnt[i]; }
	inline void Q(){ /*count();*/ }
};

/*

注： 1) 支持在线维护本质不同回文串个数 p-2 , 所有回文串个数 sum_cnt , 每个回文串出现的一次起点下标 ( 不保证最左最右 ) 

     2) 注意 id[x] 是不准确的

*/

/*

6
1 a
1 b
2 a
2 c
3
4
8
1 a
2 a
2 a
1 a
3
1 b
3
4

4
5
4
5
11

1 左 2 右
3 p-2
4 sum_cnt

*/
