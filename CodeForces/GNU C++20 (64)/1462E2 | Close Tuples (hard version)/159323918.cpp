/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int MOD = 1e9 + 7;
void add(int &a, int b, int mod = MOD){ a += b; while (a < 0) a += mod; while (a >= mod) a -= mod; }
int sum(int a, int b, int mod = MOD){ return add(a, b, mod), a; }
void mul(int &a, int b, int mod = MOD){ a = (a * 1LL * b) % mod; }
int prod(int a, int b, int mod = MOD){ return mul(a, b, mod), a; }
int bpow(int a, int b, int mod = MOD){ int ans = 1; while (b){ if (b & 1){ mul(ans, a, mod); } mul(a, a, mod); b >>= 1; } return ans; }
int Inv(int a, int mod = MOD){ return bpow(a, mod - 2, mod); }
int Div(int a, int b, int mod = MOD) { return prod(a, Inv(b, mod), mod); }
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], fact[N];
 
void precal(){
    fact[0] = 1;
    for(int i = 1; i < N; ++i) fact[i] = prod(fact[i - 1], i);
}
 
int C(int n, int k){
 if (n < k) return 0;
 return Div(fact[n], prod(fact[k], fact[n - k]));
}
 
void solve()
{
    int n, m, k, ans = 0; cin >> n >> m >> k;
 for(int i = 1; i <= n; ++i) cin >> a[i];
 sort(a + 1, a + n + 1);
 for(int i = 1, j = 1; i <= n; ++i){
  while (j <= n && a[j] - a[i] <= k) ++j;
  add(ans, C(j - i - 1, m - 1));
 }
 cout << ans << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    precal();
    int t = 1; cin >> t;
    while (t--)
    {
        solve();
    }
}