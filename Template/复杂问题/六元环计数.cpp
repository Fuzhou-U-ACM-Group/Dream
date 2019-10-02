// ans = 非六元简单环计数 六元环 = (只用走六步的所有方案 - ans) / 6 
// time : O(n^3 / 64)
const int N = 1e3 + 7;
bitset<N> a[N];
int n; string s;
ll ans, b[9], f[N], g[N], d[N];
ll c[9] = {24, 48, 2, 12, 6, 12, 36, 12, 24};

int main(){
    rep(i, 1, N) f[i] = i * (i-1) / 2, g[i] = i * (i-1) * (i-2) / 6;
    while (cin >> n){
        rep(i, 0, n) a[i].reset();
        rep(i, 0, n) {
        	cin >> s;
            rep(j, 0, n) if (s[j] == '1') a[i].set(j);
            d[i] = a[i].count();
        }
        rep(i, 0, n)
        	rep(j, i+1, n) {
                int x = (a[i] & a[j]).count();
                if (a[i][j]) b[0] += x;
                b[1]+=f[x];
                if (a[i][j]) b[2]++;
                if (a[i][j]) b[4] += (d[i]-1)*(d[j]-1);
                if (a[i][j]) b[6] += f[x];
                b[7] += f[x] * (d[i] + d[j] - 4);
            }
        rep(i, 0, n) {
            b[3] += f[d[i]];
            b[5] += g[d[i]];
            ll res = 0;
            rep(j, 0, n) if (a[i][j]) res += (a[i] & a[j]).count();
            res /= 2; b[8] += res * (res - 1) / 2;
        }
        b[0]/=3; b[1]/=2; b[4]-=3*b[0]; b[7]-=2*b[6]; b[8]-=2*b[6]; ans=0;
        rep(i, 0, 9) ans += b[i] * c[i], b[i] = 0;
        cout << ans << endl;
    }
    return 0;
}

