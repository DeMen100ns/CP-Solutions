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
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N];
 
int solve(int pos, int n){
    int sum = 0;
    if (pos > 1 && a[pos] != a[pos - 1]) sum += (pos - 1) * 1ll * (n - pos + 1);
    if (pos < n && a[pos] != a[pos + 1]) sum += pos * 1ll * (n - pos);
 
    return sum;
}
 
void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
 
    int ans = n * 1ll * (n + 1) / 2;
    for(int i = 2; i <= n; ++i){
        if (a[i] != a[i - 1]) ans += (i - 1) * 1ll * (n - i + 1);
    }
    while (m--){
        int pos, val; cin >> pos >> val;
        ans -= solve(pos, n);
        a[pos] = val;
        ans += solve(pos, n);
 
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