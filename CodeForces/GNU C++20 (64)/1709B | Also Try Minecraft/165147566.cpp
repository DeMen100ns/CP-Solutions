/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], pre[N], suf[N];
 
void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i < n; ++i){
        int x = max(0ll, a[i] - a[i + 1]);
        pre[i] = pre[i - 1] + x;
    }
    for(int i = n; i > 1; --i){
        int x = max(0ll, a[i] - a[i - 1]);
        suf[i] = suf[i + 1] + x;
    }
    while (m--){
        int s, t; cin >> s >> t;
        if (s < t){
            cout << pre[t - 1] - pre[s - 1];
        } else {
            cout << suf[t + 1] - suf[s + 1];
        }
        cout << endl;
    }
    //[1, 2]
    //pre[1] = 2 - 1
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