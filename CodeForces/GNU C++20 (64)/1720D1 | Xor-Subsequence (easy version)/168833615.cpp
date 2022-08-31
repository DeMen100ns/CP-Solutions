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
 
const int N = 3e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], dp[N], mdp[N];
 
void solve()
{
    int n; cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int ma = 0;
    for(int i = 0; i < n; ++i){
        dp[i] = 1;
       // if (i >= 520) dp[i] = mdp[i - 520] + 1;
        for(int j = i - 1; j > i - 520; --j){
            if ((a[j] ^ i) < (a[i] ^ j)) dp[i] = max(dp[i], dp[j] + 1);
        }
        ma = max(ma, dp[i]);
    }
    cout << ma << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1; cin >> t;
    while (t--)
    {
        solve();
    }
}