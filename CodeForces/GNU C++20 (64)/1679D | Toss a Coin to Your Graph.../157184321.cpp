/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9 + 5;
const int B = sqrt(N) + 5;
 
vector <int> a[N], topo;
vector <array<int, 2>> edge;
int v[N], pos[N];
int f[N];
bool g = false;
 
int dp[N];
 
void dfs_topo(int u){
    f[u] = true;
    for(int i : a[u]){
        if (!f[i]) dfs_topo(i);
    }
    topo.push_back(u);
}
 
int dfs(int u){
    f[u] = 1;
    for(int i : a[u]){
        if (f[i] == 2) continue;
        if (f[i] == 1){
            return i;
        }
        int v = dfs(i);
        if (v > 0) {
            if (v == i){
                return -1;
            } else return v;
        }
        if (v == -1) return -1;
    }
    f[u] = 2;
    return 0;
}
 
void solve()
{
    int n, m, k, mi = MAXA;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) cin >> v[i], mi = min(mi, v[i]);
    for(int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v;
        edge.push_back({u, v});
    }
 
    int l = mi - 1, r = MAXA;
    while (l + 1 < r){
        int mid = (l + r) >> 1;
        g = false;
        for(int i = 1; i <= n; ++i) a[i].clear(), f[i] = false;
        for(array<int, 2> e : edge){
            if (max(v[e[0]], v[e[1]]) <= mid){
                a[e[0]].push_back(e[1]);
               // cout << "e : " << e[0] << " " << e[1] << endl;
            }
        }
        topo.clear();
        for(int i = 1; i <= n; ++i){
            if (!f[i] && v[i] <= mid) dfs_topo(i);
        }
        fill(f + 1, f + n + 1, 0);
        fill(dp + 1, dp + n + 1, 0);
        for(int i = 1; i <= n; ++i){
            if (!f[i]){
                int v = dfs(i);
                if (v != 0){
                    g = true;
                    break;
                }
            }
        }
        reverse(topo.begin(), topo.end());
       // cout << mid << " " << g << endl;
        int ma = 0;
        if (g) r = mid;
        else {
            for(int u : topo){
                for(int v : a[u]){
                    dp[v] = max(dp[v], dp[u] + 1);
                    ma = max(ma, dp[v]);
                }
            }
            //cout << "m : " << ma << endl;
            if (ma >= k - 1) r = mid;
            else l = mid;
        }
    }
    if (r == MAXA) cout << -1;
    else cout << r;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1; //cin >> t;
    while (t--)
    {
        solve();
    }
}