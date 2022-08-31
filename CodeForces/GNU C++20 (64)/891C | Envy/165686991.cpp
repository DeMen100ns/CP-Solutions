/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 5e5;
const int B = sqrt(N) + 5;
 
int p[N], siz[N], u[N], v[N], w[N];
stack <array<int, 4>> st;
vector <int> edge[N];
vector <pair<int, int>> qu[N];
bool ans[N];
 
int root(int u){
    if (u == p[u]) return u;
    else return root(p[u]);
}
 
bool Union(int u, int v, int &cnt){
    u = root(u), v = root(v);
    if (u == v) return false;
    if (siz[u] < siz[v]) swap(u, v);
    st.push({u, v, siz[u], siz[v]});
    p[v] = u; siz[u] += siz[v]; ++cnt;
    return true;
}
 
void rollback(){
    array <int, 4> state = st.top();
    st.pop();
    int u = state[0], v = state[1];
    p[u] = u; p[v] = v;
    siz[u] = state[2]; siz[v] = state[3];
}
 
void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        cin >> u[i] >> v[i] >> w[i];
        edge[w[i]].push_back(i);
    }
    int q; cin >> q;
    for(int i = 1; i <= q; ++i){
        int k; cin >> k;
        while (k--){
            int id; cin >> id;
            qu[w[id]].push_back({i, id});
        }
    }
    iota(p + 1, p + n + 1, 1);
    fill(siz + 1, siz + n + 1, 1);
    fill(ans + 1, ans + q + 1, true);
    for(int i = 1; i <= MAXA; ++i){
        int cnt = 0, last = 0;
        for(pair<int, int> state : qu[i]){
            int que = state.first, id = state.second;
            if (que != last){
                while(cnt--) rollback();
                cnt = 0; last = que;
            }
            ans[que] &= Union(u[id], v[id], cnt);
        }
 
        for(int id : edge[i]){
            Union(u[id], v[id], cnt);
        }
    }
    for(int i = 1; i <= q; ++i){
        if (ans[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
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