/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

void solve()
{
    int n, m; cin >> n >> m;
    scc_graph a(n);
    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        a.add_edge(u, v);
    }
    vector<vector<int>> ans = a.scc();
    cout << ans.size() << endl;
    for(auto v : ans){
        cout << v.size() << " ";
        for(int u : v){
            cout << u << " ";
        } cout << endl;
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