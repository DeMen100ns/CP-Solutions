/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
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
 
array<int, 3> a[N];
vector <pair<int, int>> r, b;
int p[N], c[N], sz[N];
 
int root(int v){
     if (p[v]==v) return v;
     else return root(p[v]);
}
 
void Union(int u, int v){
    int x=root(u);
    int y=root(v);
    if (x==y) return;
    if (sz[x]<sz[y]) swap(x,y);
    sz[x]+=sz[y];
    p[y]=x;
}
 
void union_range(int p, int l, int r){
    if (l > r) return;
    Union(p, l);
    for(int i = l + 1, tmp; i <= r; i = tmp){
        Union(i, i - 1);
        tmp = c[i];
        c[i] = c[r];
    }
}
 
void solve()
{
    int n; cin >> n;
    r.clear(); b.clear();
    for(int i = 1; i <= n; ++i){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        if (a[i][0] == 0){
            r.push_back({a[i][1], a[i][2]});
        } else {
            b.push_back({a[i][1], a[i][2]});
        }
    }
    int m1 = r.size(), m2 = b.size();
    sort(r.begin(), r.end());
    sort(b.begin(), b.end());
    for(int i = 1; i <= n; ++i){
        p[i] = i; c[i] = i + 1; sz[i] = 1;
    }
    for(int i = 0; i < m1; ++i){
        int le = r[i].first, ri = r[i].second;
        pair<int, int> boundle = {le, -1}, boundri = {ri, MAXA};
        int lb = lower_bound(b.begin(), b.end(), boundle) - b.begin();
        int rb = lower_bound(b.begin(), b.end(), boundri) - b.begin() - 1;
        union_range(i + 1, m1 + lb + 1, m1 + rb + 1);
    }
    for(int i = 0; i < m2; ++i){
        int le = b[i].first, ri = b[i].second;
        pair<int, int> boundle = {le, -1}, boundri = {ri, MAXA};
        int lb = lower_bound(r.begin(), r.end(), boundle) - r.begin();
        int rb = lower_bound(r.begin(), r.end(), boundri) - r.begin() - 1;
        union_range(m1 + i + 1, lb + 1, rb + 1);
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i) cnt += (p[i] == i);
    cout << cnt << endl;
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