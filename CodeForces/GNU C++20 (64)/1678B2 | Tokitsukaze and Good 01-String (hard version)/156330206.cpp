/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
#define x first
#define y second
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
ii dp[N][2][2];
 
void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= 1; ++j){
            for(int p = 0; p <= 1; ++p) dp[i][j][p] = {MAXA, MAXA};
        }
    }
    for(int i = 1; i <= n; ++i){
        int v = s[i] - '0'; ii st;
        dp[i][v][0] = dp[i - 1][v][1];
        st = {dp[i - 1][v ^ 1][0].x, dp[i - 1][v ^ 1][0].y + 1};
        dp[i][v][1] = min(st, dp[i - 1][v][0]);
        dp[i][v ^ 1][0] = dp[i - 1][v ^ 1][1];
        st = {dp[i - 1][v][0].x, dp[i - 1][v][0].y + 1};
        dp[i][v ^ 1][1] = min(st, dp[i - 1][v ^ 1][0]);
        dp[i][v ^ 1][0].x++; dp[i][v ^ 1][1].x++;
    }
    ii ans = {MAXA, MAXA};
    for(int j = 0; j <= 1; ++j){
        ans = min(ans, dp[n][j][0]);
    }
    cout << ans.x << " " << ans.y + 1 << endl;
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