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
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = 300;
 
vector <pair<int, int>> edge[N];
vector <int> node[N];
int p[N], siz[N], ans[N], U[N], V[N];
map<pair<int, int>, int> cnt;
 
int root(int u){
    if (u == p[u]) return u;
    else return p[u] = root(p[u]);
}
 
void Union(int u, int v){
    u = root(u); v = root(v);
    if (u == v) return;
 
    if (siz[u] < siz[v]) swap(u, v);
    p[v] = u;
    siz[u] += siz[v];
}
 
void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v, c; cin >> u >> v >> c;
        edge[c].push_back({u, v});
        node[c].push_back(u);
        node[c].push_back(v);
    }
    for(int i = 1; i <= m; ++i){
        sort(node[i].begin(), node[i].end());
        node[i].resize(unique(node[i].begin(), node[i].end()) - node[i].begin());
    }
 
    int q; cin >> q;
    for(int i = 1; i <= q; ++i){
        cin >> U[i] >> V[i];
        if (U[i] > V[i]) swap(U[i], V[i]);
    }
 
    iota(p + 1, p + n + 1, 1);
    fill(siz + 1, siz + n + 1, 1);
 
    for(int i = 1; i <= m; ++i){
        for(pair<int, int> e : edge[i]){
            Union(e.first, e.second);
        }
 
        if (edge[i].size() < B){
            for(int u : node[i]){
                for(int v : node[i]){
                    if (u > v || root(u) != root(v)) continue;
                    cnt[{u, v}]++;
                }
            }
        } else {
            for(int i = 1; i <= q; ++i){
                ans[i] += (root(U[i]) == root(V[i]));
            }
        }
 
        for(int u : node[i]){
            p[u] = u; siz[u] = 1;
        }
    }
 
    for(int i = 1; i <= q; ++i){
        cout << ans[i] + cnt[{U[i], V[i]}] << endl;
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