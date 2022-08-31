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
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
void solve()
{
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
 
    if ((sx - d <= 1 && sy - d <= 1) || (sx + d >= n && sy + d >= m) || (sx - d <= 1 && sx + d >= n) || (sy - d <= 1 && sy + d >= m)){
        cout << -1 << endl; return;
    }
 
    cout << n + m - 2 << endl;
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