/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc

Name: Or Plus Max
Sauce: https://atcoder.jp/contests/arc100/tasks/arc100_c
Tag: DP SOS, Greedy
Sol: Easy DP SOS
Note: -
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 18;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int dp[N], cur[N];

void solve()
{
    int n; cin >> n;
    for(int i = 0; i < (1 << n); ++i) cin >> dp[i];
    for(int p = 0; p < n; ++p){
        for(int i = 0; i < (1 << n); ++i){
            if (i >> p & 1){
                cur[i] = max({cur[i], cur[i ^ (1 << p)], dp[i] + dp[i ^ (1 << p)]});
                dp[i] = max(dp[i], dp[i ^ (1 << p)]);
            }
        }
    }
    for(int i = 1; i < (1 << n); ++i){
        int ans = cur[i];
        //10100 -> 10011 -> 10100 -> 01111
        for(int p = 1; p < n; ++p){
            if (i >> p & 1){
                ans = max(ans, cur[(i ^ (1 << p)) | ((1 << p) - 1)]);
            }
        }
        cout << ans << endl;
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