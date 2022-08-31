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
 
vector <int> a[N], b[N];
 
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int j = 1; j <= m; ++j){
        a[j] = {0};
        b[j] = {0};
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int v; cin >> v;
            a[j].push_back(v);
            b[j].push_back(v);
        }
    }
 
    sort(a + 1, a + m + 1);
 
    bool f = true;
    for(int i = 1; i < m; ++i){
        for(int j = 1; j <= n; ++j){
            f &= (a[i][j] <= a[i + 1][j]);
        }
    }
 
    if (!f){
        cout << -1 << endl;
        return;
    }
 
    vector <int> ans;
 
    for(int i = 1; i <= m; ++i){
        if (a[i] != b[i]){
            ans.push_back(i);
        }
        if (ans.size() > 2){
            cout << -1 << endl;
            return;
        }
    }
    if (ans.size() == 2){
        cout << ans[0] << " " << ans[1] << endl;
    } else {
        cout << 1 << " " << 1 << endl;
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