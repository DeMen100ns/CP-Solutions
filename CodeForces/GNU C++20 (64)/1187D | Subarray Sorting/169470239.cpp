#include <random>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <chrono>
#include <set>
#include <queue>
#include <map>
using namespace std;
int n;
const int maxn = 3e5;
vector<int> pos[maxn+5];
long long a[maxn+5], b[maxn+5];
long long seg[4*maxn+5];
void update(int node, int l, int r, int idx, long long x)
{
    if(idx < l || idx > r) return;
    if(idx == l && idx == r)
    {
        //cout << l << ' ' << r << ' ' << x << '\n';
        seg[node] = x;
        return;
    }
    int mid = (l+r)/2;
    update(node*2,l,mid,idx,x);
    update(node*2+1,mid+1,r,idx,x);
    seg[node] = min(seg[node*2],seg[node*2+1]);
}
long long query(int node, int l, int r, int u, int v)
{
    //cout << seg[node] << ' ' << node << '\n';
    if(l > v || r < u) return 1e9;
    if(u <= l && r <= v) return seg[node];
    int mid = (l+r)/2;
    long long le = query(node*2, l ,mid, u, v);
    long long ri = query(node*2+1,mid+1,r,u,v);
    return min(le,ri);
}
void solve()
{
     cin >> n;
     for(int i = 1; i <= n; i++)
     {
         cin >> a[i];
         update(1,1,n,i,a[i]);
     }
 
     for(int i = 1; i <= n; i++)
        cin >> b[i];
     for(int i = n; i >= 1; i--)
        pos[a[i]].push_back(i);
     bool flag = true;
     for(int i = 1; i <= n; i++)
     {
         if(pos[b[i]].empty())
         {
            // cout << "now" << endl;
             flag = false;
             break;
         }
         int cur = pos[b[i]].back();
         pos[b[i]].pop_back();
         long long x = query(1,1,n,1,cur);
       //  cout << "check " << x << ' ' << cur << ' ' << b[i] << '\n';
         if(x < b[i])
         {
         //    cout << "des " << i << '\n';
             flag = false;
             break;
         }
         update(1,1,n,cur,1e9);
    }
 
    if(flag) cout << "YES\n";
    else cout << "NO\n";
    for(int i = 1; i <= n; i++) pos[i].clear();
}
int main() {
    ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while(t--)
    solve();
    return 0;
}