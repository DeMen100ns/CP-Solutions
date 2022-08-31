/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int N = 1e5 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int dp[N][1 << 7];
array<int, 8> a[N];
 
void solve()
{
    int n, p, k; cin >> n >> p >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i][0];
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < p; ++j) cin >> a[i][j + 1];
    }
    sort(a + 1, a + n + 1, greater<array<int, 8>>());
    for(int i = 0; i <= n; ++i){
        if (i) swap(a[i][0], a[i][p]);
        for(int j = 0; j < (1 << p); ++j) dp[i][j] = -INF;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i){
        for(int m = 0; m < (1 << p); ++m){
            for(int j = 0; j < p; ++j){
                if (m >> j & 1){
                    dp[i][m] = max(dp[i][m], dp[i - 1][m ^ (1 << j)] + a[i][j]);
                }
            }
            int tmp = dp[i - 1][m];
            if (i - __builtin_popcount(m) <= k) tmp += a[i][p];
            dp[i][m] = max(dp[i][m], tmp);
        }
    }
    cout << dp[n][(1 << p) - 1];
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1; //cin >> t;
    while (t--)
    {
        solve();
    }
}