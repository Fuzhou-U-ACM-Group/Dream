const int N = 2e5 + 100, maxlog = 20;
struct Seq{
    /** l + k*d <=r **/
    int l,r,d;
	Seq(int l = 0, int r = 0, int d = 0) : l(l), r(r), d(d) {}
    Seq(const vi & pos){
        if (pos.empty()){
            l = r = d = 0;
        }else if (pos.size() == 1){
            l = pos.front();
            r = pos.front();
            d = 1;
        }else{
            l = pos.front();
            r = pos.back();
            d = pos[1] - pos[0];
        }
    }
    bool has(int x){ return d and x >= l and x <= r and x % d == l % d; }
    int count(){
        if (d == 0)return 0;
        return (r - l) / d + 1;
    }
    vi to_list(){
        vi list(0);
        if (d == 0)return list;
        for (int i=l;i<=r;i+=d)list.pb(i);
        return list;
    }
};
Seq operator -(int X, Seq S){return Seq(X - S.r,X - S.l, S.d);}
Seq operator -(Seq S, int X){return Seq(S.l - X, S.r - X, S.d);}
Seq operator &(Seq S1, Seq S2){
    int cnt1 = S1.count(), cnt2 = S2.count();
    if (cnt1 == 0 || cnt2 == 0) return Seq(0,0,0);
    if (cnt1 > cnt2) swap(S1,S2), swap(cnt1,cnt2);
    if (cnt1 < 3){
        vi pos(0);
        for (int x : S1.to_list()){
            if (S2.has(x)) pos.pb(x);
        }
        return Seq(pos);
    }else{
        if (S1.d == S2.d){
            int l = max(S1.l,S2.l), r = min(S1.r,S2.r);
            if (r >= l && S1.l % S1.d == S2.l % S1.d)return Seq(l,r,S1.d);
            else return Seq(0,0,0);
        }else assert(0);
    }
}
struct Dictionary_of_Basic_Factories{
    /** 1-base **/
    vector<vi> pos[maxlog];
    int name[N][maxlog], cntA[N],cntB[N],tsa[N],A[N],B[N], sa[N],rk[N];
    void init(char *ch, int n){
        ch[0] = ch[n+1] = -1;
        for (int i=1;i<=n;i++)cntA[ch[i]]++;
        for (int i=1;i<N;i++)cntA[i] += cntA[i-1];
        for (int i=n;i>=1;i--)sa[cntA[ch[i]]--] = i;
        rk[sa[1]] = 1;
        for (int i=2;i<=n;i++){
            rk[sa[i]] = rk[sa[i-1]];
            if (ch[sa[i]] != ch[sa[i-1]])rk[sa[i]] ++;
        }
        pos[0].resize(rk[sa[n]] + 1,vi(0));
        for (int i=1;i<=n;i++){
            name[i][0] = rk[i];
            pos[0][rk[i]].pb(i);
        }
        for (int step = 1,l=1;l <= n;l<<=1,step ++){
            for (int i=0;i<=n;i++)cntA[i] = cntB[i] = 0;
            for (int i=1;i<=n;i++){
                cntA[A[i] = rk[i]] ++;
                cntB[B[i]=(i+l<=n)?rk[i+l]:0]++;
            }
            for (int i=1;i<=n;i++)cntB[i] += cntB[i-1];
            for (int i=n;i>=1;i--)tsa[cntB[B[i]]--] = i;
            for (int i=1;i<=n;i++)cntA[i] += cntA[i-1];
            for (int i=n;i>=1;i--)sa[cntA[A[tsa[i]]]--] = tsa[i];
            rk[sa[1]] = 1;
            for (int i=2;i<=n;i++){
                rk[sa[i]] = rk[sa[i-1]];
                if (A[sa[i]] != A[sa[i-1]] || B[sa[i]] != B[sa[i-1]])rk[sa[i]] ++;
            }
            pos[step].resize(rk[sa[n]] + 1,vi (0));
            for (int i = 1;i <=n;i++){
                name[i][step] = rk[i];
                pos[step][rk[i]].pb(i);
            }
        }
    }
    // get sequence [2^step,2^(step+1))
    Seq get_seq(vi & list, int l, int r){
        vi pos(0);
        int idx = lower_bound(list.begin(),list.end(),l) - list.begin();
        while (idx < list.size() && pos.size() < 3 && list[idx] <= r){
            pos.pb(list[idx]);idx ++;
        }
        if (pos.size() < 3)return Seq(pos);
        else{
            int last = upper_bound(list.begin(),list.end(),r) - list.begin() - 1;
            int L = pos.front(), d = pos[1] - pos[0], R = list[last];
            return Seq(L,R,d);
        }
    }
    Seq get_border(int l,int r,int step){
        int len = r - l + 1;
        int baby = 1 << step, giant = min(len-1,(baby * 2-1));
        int namel = name[l][step], namer = name[r - baby + 1][step];
        Seq seql = get_seq(pos[step][namel],r - giant + 1,r - baby + 1),
            seqr = get_seq(pos[step][namer],l,l + giant - baby);
        seql = (r + 1) - seql; seqr = seqr - (l -baby);
        return  seql & seqr;
    }
    /** return O(logn) border series of S[l,r].
     * Attention: can contain empty sequence (0,0,0)
     * if [2^i,2^(i+1)) border does not exist.*/
    vector<Seq> get_border_series(int l,int r){
        vector<Seq> ret(0);
        for (int step = 0;(1<<step) < r - l + 1;step++) ret.pb(get_border(l,r,step));
        return ret;
    }
    int get_biggest_border(int l,int r){
        int len = r - l + 1;
        for (int k = maxlog - 1; k >=0;k--){
            if ((1<<k) >= len)continue;
            Seq seq = get_border(l,r,k);
            if (seq.r)return seq.r;
        }
        return 0;
    }
}dbf;
char s[N]; int n,q;
int main(){
    scanf("%d%d",&n, &q);
    scanf("%s",s + 1);
    dbf.init(s, n);
    while (q--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",dbf.get_biggest_border(l,r));
    }
    return 0;
}