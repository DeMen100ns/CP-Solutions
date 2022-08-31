/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
vector <int> a[N];
int p[30][N], siz[30][N], ct2[N];
int p1[30][N], siz1[30][N];
bool val[30][N], val0[30][N];
 
int root(int p[], int u){
    if (u == p[u]) return u;
    else return p[u] = root(p, p[u]);
}
 
void Union(int p[], int siz[], bool val[], int u, int v){
    u = root(p, u); v = root(p, v);  
    if (u == v) return;
    if (siz[u] < siz[v]) swap(u, v);
    p[v] = u;
    siz[u] += siz[v];
    val[u] |= val[v];
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 30; ++j){
            p[j][i] = p1[j][i] = i;
            siz[j][i] = siz1[j][i] = 1;
        }
    }
    for(int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        for(int j = 0; j < 30; ++j){
            if (w & (1 << j)){
                Union(p[j], siz[j], val0[j], u, v);
                if (j > 0 && (w & 1)){
                    Union(p1[j], siz1[j], val[j], u, v);
                }
            }
        }
        if ((w & 1) == 0){ 
            ct2[u]++;
            ct2[v]++;
            for(int j = 1; j < 30; ++j){
                val[j][root(p1[j], u)] = val[j][root(p1[j], v)] = true;
            }
        }
    }
    int q; cin >> q;
    for(int i = 1; i <= q; ++i){
        int u, v, ans = 2; 
        cin >> u >> v;
        for(int j = 0; j < 30; ++j){
            if (root(p[j], u) == root(p[j], v)){
                ans = 0;
                break;
            }
        }
        if (ans){
            if (ct2[u]) ans = 1;
            else{
                for(int j = 1; j < 30; ++j){
                    if (val[j][root(p1[j], u)]) ans = 1;
                }
            }
        }
        cout << ans << endl;
    } 
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