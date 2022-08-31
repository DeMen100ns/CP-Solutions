/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 3e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int l[N], r[N], sub[N], dp[N];
vector <int> a[N];
 
void dfs(int u, int par = 1){
    for(int i : a[u]){
        if (i == par) continue; 
        dfs(i, u);
        sub[u] += sub[i];
        if (!l[u]) l[u] = i;
        else r[u] = i;
    }
    ++sub[u];
}
 
void dfs_cal(int u){
    if (u == 0) return;
    dfs_cal(l[u]); dfs_cal(r[u]);
    if (!r[u]) dp[u] = max(0, sub[l[u]] - 1);
    else {
        dp[u] = max(sub[l[u]] + dp[r[u]], dp[l[u]] + sub[r[u]]) - 1;
    }
}
 
void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        l[i] = r[i] = dp[i] = sub[i] = 0;
        a[i].clear();
    }
    for(int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    dfs_cal(1);
    cout << dp[1] << endl;
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