/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
 
const int N = 4e4 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int dp[N];
vector <int> v;
 
void solve()
{
    int n; cin >> n;
    cout << dp[n] << endl;
}
 
bool check(int n){
    int r = 0;
    int cd = n;
    while (cd){
        r *= 10;
        r += cd % 10;
        cd /= 10;
    }
    return (r == n);
}
 
void precal(){
    int n = 4e4;
    for(int i = 1; i <= n; ++i){
        if (check(i)) v.push_back(i);
    }
    dp[0] = 1;
    for(int val : v){
        for(int j = 0; j <= n - val; ++j){
            add(dp[j + val], dp[j]);
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1; cin >> t;
    precal();
    while (t--)
    {
        solve();
    }
}