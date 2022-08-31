/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
void solve()
{
    vector <pair<int, int>> v;
    int n, m;
    cin >> n >> m;
    int mix = n, miy = m;
    pair<int, int> mi = {n, m};
    int ans = 2 * n + 2 * m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char c; cin >> c;
            if (c == 'R'){
                mix = min(mix, i - 1);
                miy = min(miy, j - 1);
                mi = min(mi, {i - 1, j - 1});
            }
        }
    }
    if (mix == mi.first && miy == mi.second){
        cout << "YES";
    } else cout << "NO";
    cout << endl;
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