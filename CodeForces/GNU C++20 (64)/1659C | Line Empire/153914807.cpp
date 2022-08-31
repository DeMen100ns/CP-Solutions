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
 
int a[N], suf[N];
 
void solve()
{
    int n, ca, cb;
    cin >> n >> ca >> cb;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    if (n == 1){
        cout << cb * a[1] << endl;
        return;
    }
    if (ca <= cb){
        cout << (ca + cb) * a[n] - ca * (a[n] - a[n - 1]) << endl;
    } else {
        int ans = (ca + cb) * a[n] - ca * (a[n] - a[n - 1]);
        int g = 0;
        suf[n + 1] = 0;
        for(int i = n; i >= 1; --i){
            suf[i] = suf[i + 1] + a[i];
        }
        for(int i = 1; i < n; ++i){
            int ma1 = (a[n] - a[i - 1]) * (ca + cb) - ca * (a[n] - a[n - 1]);
            int ma2 = cb * (suf[i] - a[i - 1] * (n - i + 1));
            g = min(g, ma2 - ma1);
        }
        cout << ans + g << endl;
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
    while (t--)
    {
        solve();
    }
}