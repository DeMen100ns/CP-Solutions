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
 
bool a[501][501];
 
void solve()
{
    int n, m, ct = 0; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char c; cin >> c;
            a[i][j] = (c == '1');
            ct += a[i][j];
        }
    }
    int mi = 4;
    for(int i = 1; i < n; ++i){
        for(int j = 1; j < m; ++j){
            int sum = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
            sum -= max({a[i][j], a[i][j + 1], a[i + 1][j], a[i + 1][j + 1]});
 
            mi = min(mi, sum);
        }
    }
    if (mi > 1) ct -= (mi - 1);
    cout << ct << endl;
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