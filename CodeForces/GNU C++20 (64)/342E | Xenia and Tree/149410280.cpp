#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
vector <int> a[N], cen[N];
bool vis[N];
int sub[N], h[N], p[N], ans[N];
unordered_map <int, int> d[N];
int n;
 
void dfs_siz(int u, int par = 0){
    sub[u] = 1;
    for(int i : a[u]){
        if (i == par || vis[i]) continue;
        dfs_siz(i, u);
        sub[u] += sub[i];
    }
}
 
void dfs_dis(int u, int C, int par = 0, int dis = 0){
    d[C][u] = dis;
    for(int i : a[u]){
        if (i == par || vis[i]) continue;
        dfs_dis(i, C, u, dis + 1);
    }
}
 
int find_centroid(int u, int sz, int par = 0){
    for(int i : a[u]){
        if (i == par || vis[i]) continue;
        if (sub[i] > sz / 2) return find_centroid(i, sz, u);
    }
    return u;
}
 
int dfs_centroid(int u){
    dfs_siz(u);
    int C = find_centroid(u, sub[u]);
    vis[C] = true;
    dfs_dis(C,C);
    for(int i : a[C]){
        if (vis[i]) continue;
        int C_sub = dfs_centroid(i);
        p[C_sub] = C;
    }
    return C;
}
 
void upd(int u){
    int v = u;
    while(v){
        ans[v] = min(ans[v], d[v][u]);
        v = p[v];
    }
}
 
int get(int u){
    int v = u;
    int res = 1e9;
    while(v){
        res = min(res, ans[v] + d[v][u]);
        v = p[v];
    }
    return res;
}
 
void solve(){
    int q;
    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs_centroid(1);
    for(int i = 1; i <= n; ++i) ans[i] = n + 1;
    upd(1);
    while (q--){
        int type, u;
        cin >> type >> u;
        if (type == 1){
            upd(u);
        } else {
            cout << get(u) << endl;
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; //cin >> t;
    while (t--){
        solve();
    }
}