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

const int MOD = 998244353;
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}

const int N = 300 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int dp[N][N * N + N], dpsub[N][N * N + N];

void solve()
{
    dp[0][0] = dpsub[0][0] = 1;
    int n, sum = 0, ans = 1; cin >> n;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        for(int j = 0; j <= sum; ++j){
            add(dp[i][j + x], dp[i - 1][j]);
            add(dp[i][j], prod(dp[i - 1][j], 2));
            add(dpsub[i][j + x], dpsub[i - 1][j]);
            add(dpsub[i][j], dpsub[i - 1][j]);
        }
        sum += x; mul(ans, 3);
    }
    
    for(int j = sum / 2; j <= sum; ++j){
        if (j * 2 < sum) continue;

        add(ans, -prod(3, dp[n][j]));
    }
    if (sum % 2 == 0) add(ans, prod(3, dpsub[n][sum / 2]));
    cout << ans;
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