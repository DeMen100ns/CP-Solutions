/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], dp[N];
 
void solve()
{
    int n; cin >> n;
    int ans = 0;
    int k = 32768;
    for(int i = 1; i < k; ++i){
        int g = i;
        while (g){
            dp[i]++;
            g = (g * 2) % k;
        }
    }
    for(int i = k - 1; i; --i){
        dp[i] = min({dp[i], dp[i * 2 % k] + 1, dp[(i + 1) % k] + 1});
    }
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        cout << dp[x] << " ";
    }
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