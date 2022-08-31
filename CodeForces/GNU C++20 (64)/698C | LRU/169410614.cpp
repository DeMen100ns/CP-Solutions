/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
 
Name:
Sauce: 
Tag: 
Sol: 
Note: 
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
long double a[22], ans[22], dp[1 << 22];
 
void solve()
{
    int n, k, cnt = 0; cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        cnt += (a[i] > 1e-6);
    }
    k = min(k, cnt);
    dp[0] = 1;
    for(int i = 1; i < (1 << n); ++i){
        long double s = 0;
        for(int j = 0; j < n; ++j){
            if (i >> j & 1) s += a[j];
        }
        for(int j = 0; j < n; ++j){
            if (i >> j & 1) dp[i] += dp[i ^ (1 << j)] * a[j] / (1.d - s + a[j]);
        }
        if (__builtin_popcount(i) == k){
            for(int j = 0; j < n; ++j){
                if (i >> j & 1) ans[j] += dp[i];
            }
        }
    }
    for(int i = 0; i < n; ++i) cout << fixed << setprecision(9) << ans[i] << " ";
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1; // cin >> t;
    while (t--)
    {
        solve();
    }
}