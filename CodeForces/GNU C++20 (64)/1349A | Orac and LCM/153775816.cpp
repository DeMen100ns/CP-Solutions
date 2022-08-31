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
 
int a[N], pref[N], suf[N], g[N];
 
int lcm(int a, int b){
    return a / __gcd(a, b) * b;
}
 
void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) pref[i] = __gcd(pref[i - 1], a[i]);
    for(int i = 1; i <= n; ++i) suf[i] = __gcd(suf[i + 1], a[i]);
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        g[i] = __gcd(pref[i - 1], suf[i + 1]);
        g[i] = lcm(g[i], a[i]);
        ans = __gcd(ans, g[i]);
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