/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
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

const int N = 100 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int a[N], gt[N], dp[N][N * N];

void solve()
{
    int n, s = 0; cin >> n;
    gt[0] = 1;
    for(int i = 1; i <= n; ++i){
        cin >> a[i]; s += a[i];
        gt[i] = prod(gt[i - 1], i);
    }
    if (s & 1){
        cout << 0; return;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = i; j; --j){
            for(int s = j * 100; s >= a[i]; --s){
                add(dp[j][s], dp[j - 1][s - a[i]]);
            }
        }
    }
    int ans = 0;
    for(int k = 1; k < n; ++k){
        add(ans, prod(dp[k][s >> 1], prod(gt[k], gt[n - k])));
    }
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