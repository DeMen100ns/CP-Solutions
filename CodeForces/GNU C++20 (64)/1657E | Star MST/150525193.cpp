/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 250 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
const int MOD = 998244353;
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod; }
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod; }
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x; }
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x; }
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1; } return ans; }
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod); }
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod); }
 
int dp[N][N][N];
 
void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; ++i) dp[2][i][1] = 1;
    for(int i = 2; i < n; ++i){
     for(int j = 1; j <= k; ++j){
      int s = 0;
      for(int edge = 1; edge <= n; ++edge){
       add(dp[i + 1][j][edge + 1], prod(dp[i][j][edge], prod(bpow(k - j + 1, i - 1), Div(i, edge + 1))));
       add(s, dp[i][j][edge]);
      }
      for(int j2 = j + 1; j2 <= k; ++j2){
       add(dp[i + 1][j2][1], prod(s, prod(bpow(k - j2 + 1, i - 1), i)));
      }
     }
    }
    int ans = 0;
    for(int j = 1; j <= k; ++j){
     for(int edge = 1; edge <= n; ++edge){
      add(ans, dp[n][j][edge]);
     }
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
    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}