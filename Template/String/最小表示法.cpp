// 传入传出下标从 0 开始
int MINR(char s[],int L){
    rep(i,0,L) s[L+i]=s[i];
    s[2*L]=0;
    int i=0,j=1;
    while(i<L&&j<L){
        int k=0;
        while(s[i+k]==s[j+k]&&k<L)++k;
        if(k==L)return min(i,j);
		// 最大改成 < 
        if(s[i+k]>s[j+k])i=max(i+k+1,j+1);
        else j=max(j+k+1,i+1);
    }
    return min(i,j);
}
