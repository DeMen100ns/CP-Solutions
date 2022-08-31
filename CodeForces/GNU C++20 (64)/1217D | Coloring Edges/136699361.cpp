/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
#define ll long long
#define x first
#define y second
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int N = 2e5 + 5;
 
vector <pair<int, int>> a[N];
int color[N], h[N], cnt;
bool vis[N], f[N];
 
void dfs(int u){
    vis[u] = true;
    for(auto i : a[u]){
        int v = i.x, id = i.y;
        if (vis[v]){
            if (h[u] >= h[v] && f[v]) color[id] = 2;
            else color[id] = 1;
        } else {
            f[u] = true;
            h[v] = h[u] + 1;
            color[id] = 1;
            dfs(v);
            f[u] = false;
        }
    }
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        a[u].push_back({v, i});
    }
    for(int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
    int ma = 1;
    for(int i = 1; i <= m; ++i) ma = max(ma, color[i]);
    cout << ma << endl;
    for(int i = 1; i <= m; ++i) cout << color[i] << " ";
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; //cin >> t;
    while (t--){
        solve();
    }
}