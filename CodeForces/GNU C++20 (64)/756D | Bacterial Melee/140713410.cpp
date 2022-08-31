/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
long long dec(long long x, long long y, int mod = MOD) {return (x-y+mod)%mod;}
long long add(long long x, long long y, int mod = MOD) {return (x + y) % mod;}
long long mul(long long x, long long y, int mod = MOD) {return ((x%mod) * (y%mod)) % mod;}
long long bpow(long long x, long long y, int mod = MOD) {long long res = 1; while (y) {if (y & 1) res = mul(res, x, mod); x = mul(x, x, mod); y >>= 1;} return res;}
long long ModInverse(long long x, int mod = MOD) {return bpow(x, mod - 2, mod);}
long long Div(long long x, long long y, int mod = MOD) {return mul(x, ModInverse(y, mod), mod);}
 
const int N = 5e3 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], gt[N], last[N], dp[N][N];
 
int C(int n, int k){
    return Div(gt[n], mul(gt[k], gt[n - k]));
}
 
void solve(){
    gt[0] = 1;
    for(int i = 1; i <= N - 1; ++i) gt[i] = mul(gt[i - 1], i);
    string s; int n;
    cin >> n >> s;
    s.resize(unique(s.begin(), s.end()) - s.begin());
    int m = s.size(); s = " " + s;
    dp[0][0] = 1;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= m; ++j){
            if (last[s[i]] != 0) dp[i][j] = add(dp[i][j], dec(dp[i - 1][j - 1], dp[last[s[i]]][j - 1]));
            else dp[i][j] = add(dp[i][j], dp[i - 1][j - 1]);
            dp[i][j - 1] = add(dp[i][j - 1], dp[i - 1][j - 1]);
        }
        last[s[i]] = i;
    }
    int ans = 0;
    for(int j = 1; j <= m; ++j){
        //C(n + m - 1, m - 1);
        //C(n - 1, m - 1);
        ans = add(ans, mul(dp[m][j], C(n - 1, j - 1)));
    }
    cout << ans;
}
 
signed main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    //freopen("codeforces.inp","r",stdin);
    //freopen("codeforces.out","w",stdout);
    
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
}