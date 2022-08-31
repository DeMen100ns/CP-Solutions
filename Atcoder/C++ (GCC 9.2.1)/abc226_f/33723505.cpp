/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc

Name: Score of Permutations
Sauce: https://atcoder.jp/contests/abc226/tasks/abc226_f
Tag: DP, Combin
Sol: 
- S(P) = LCM(all cycle length)
- n-length sequence have (n - 1)! possible cycle
- dp[i][j] : number of i-length sequence have S() = j.
- dp[i + x][lcm(j, x)] += dp[i][j] * C(n - i - 1, x - 1) * (x - 1)!

Note: 
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
void add(int &a, int b, int mod = MOD){ a += b; while (a < 0) a += mod; while (a >= mod) a -= mod; }
int sum(int a, int b, int mod = MOD){ return add( a, b, mod), a; }
void mul(int &a, int b, int mod = MOD){ a = (a * 1LL * b) % mod; }
int prod(int a, int b, int mod = MOD){ return mul(a, b, mod), a; }
int bpow(int a, int b, int mod = MOD){ int ans = 1; while (b){ if (b & 1){ mul(ans, a, mod); } mul(a, a, mod); b >>= 1; } return ans; }
int Inv(int a, int mod = MOD){ return bpow(a, mod - 2, mod); }
int Div(int a, int b, int mod = MOD) { return prod(a, Inv(b, mod), mod); }

const int N = 50 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 2e5;
const int B = sqrt(N) + 5;

int dp[N][MAXA], fact[N], inv[N];

int lcm(int a, int b){
    return a / __gcd(a, b) * b;
}

int C(int n, int k){
    return prod(fact[n], prod(inv[n - k], inv[k]));
}

void solve()
{
    int n, k; cin >> n >> k;
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= n; ++i){
        fact[i] = prod(fact[i - 1], i);
        inv[i] = Inv(fact[i]);
    }
    dp[0][1] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 1; j < MAXA; ++j){
            if (!dp[i][j]) continue;
            for(int x = 1; i + x <= n; ++x){
                if (lcm(j, x) >= MAXA) cout << lcm(j, x) << endl;
                add(dp[i + x][lcm(j, x)], prod(dp[i][j], prod(C(n - i - 1, x - 1), fact[x - 1])));
            }
        }
    }
    int ans = 0; 
    for(int x = 1; x < MAXA; ++x){
        add(ans, prod(dp[n][x], bpow(x, k)));
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

    int t = 1; //cin >> t;
    while (t--)
    {
        solve();
    }
}