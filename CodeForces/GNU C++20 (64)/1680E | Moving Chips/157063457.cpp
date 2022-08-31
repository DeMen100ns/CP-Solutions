/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
char a[2][N];
vector <int> u, d;
int dp[N][4];
 
void solve()
{
    int n; cin >> n;
    string u, d;
    cin >> u >> d;
    u = " " + u; d = " " + d;
    for(int i = 0; i <= n; ++i){
        for(int k = 0; k < 4; ++k){
            dp[i][k] = 2 * n + 1;
        }
    }
    dp[0][0] = 0;
    int last;
    for(int i = 1; i <= n; ++i){
        int now = ((u[i] == '*') << 1) + (d[i] == '*');
        for(int last = 0; last < 4; ++last){
            dp[i][last | now] = min(dp[i][last | now], dp[i - 1][last] + __builtin_popcount(last));
        }
        int v1 = min({dp[i][1], dp[i][3] + 1, dp[i][2] + 1});
        int v2 = min({dp[i][2], dp[i][1] + 1, dp[i][3] + 1});
        dp[i][1] = v1; dp[i][2] = v2;
        if (now) last = i;
    }
    cout << min({dp[last][0], dp[last][1], dp[last][2]}) << endl;
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