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
 
int a[N], b[N], c[N], pa[N], pb[N], f[N];
bool g[N];
 
bool dfs(int u, int h){
    if (c[u] > 0) return true;
    c[u] = -1;
    int v = pb[a[u]];
    if (v == h) return false;
    g[u] = dfs(v, h);
    return g[u];
}
 
void solve()
{
    int n, ans = 1; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], pa[a[i]] = i, f[i] = false, g[i] = false;
    for(int i = 1; i <= n; ++i) cin >> b[i], pb[b[i]] = i;
    for(int i = 1; i <= n; ++i) cin >> c[i], f[c[i]] = true, g[i] = (c[i] > 0);
    for(int i = 1; i <= n; ++i){
        if (c[i] == 0){
            if (a[i] == b[i]) c[i] = b[i];
            else{
                int u = i;
                dfs(u, u);
                if (!g[u]) ans = (ans * 2) % (int)(1e9 + 7);
            }
        }
    }
    cout << ans << endl;
    /*
1 2 3 4 5 6 7
2 3 1 7 6 5 4
2 0 1 0 0 0 0
    */
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