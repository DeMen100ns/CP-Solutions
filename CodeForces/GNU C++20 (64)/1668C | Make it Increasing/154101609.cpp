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
 
int a[N], b[N];
 
void solve()
{
    int n, res = INF; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i){
        int ans = 0;
        fill(b + 1, b + n + 1, 0);
        for(int j = i - 1; j; --j){
            int k = b[j + 1] / a[j] + 1;
            ans += k;
            b[j] = k * a[j];
        }
        for(int j = i + 1; j <= n; ++j){
            int k = b[j - 1] / a[j] + 1;
            ans += k;
            b[j] = k * a[j];
        }
        res = min(res, ans);
    }
    cout << res;
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