#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>
#include <sstream>
#include <stack>
using namespace std;
int n,k;
const int maxn = 1e6;
int ans[maxn+5];
stack<int> st;
int par[maxn+5];
int a[maxn+5];
vector<int> adj[maxn+5];
int tin[maxn+5];
int tout[maxn+5];
int seg[4 * maxn+5];
int lazy[4 * maxn + 5];
int timer = 0;
void dfs(int u)
{
    tin[u] = ++timer;
   // cout << u << endl;
    for(auto v: adj[u])
        dfs(v);
    tout[u] = timer;
}
void down(int node)
{
    seg[node*2] += lazy[node];
    seg[node*2+1] += lazy[node];
    lazy[node*2] += lazy[node];
    lazy[node*2+1] += lazy[node];
    lazy[node] = 0;
}
void update(int node, int l, int r, int u, int v, int x)
{
   // cout << l << ' ' << r << ' ' << u << ' ' << v << endl;
    if(l > v || r < u) return;
    if(u <= l && r <= v)
    {
        seg[node] += x;
        lazy[node] += x;
        return;
    }
    down(node);
    int mid = (l+r)/2;
    update(node*2,l,mid,u,v,x);
    update(node*2+1,mid+1,r,u,v,x);
    seg[node] = max(seg[node*2],seg[node*2+1]);
}
void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = n; i >= 1; i--)
    {
        while(!st.empty() && a[i] >= a[st.top()]) st.pop();
        if(!st.empty())
        {
            par[i] = st.top();
            adj[st.top()].push_back(i);
        }
        st.push(i);
    }
    for(int i = n; i >= 1; i--)
    {
        if(par[i] == 0) dfs(i);
    }
 
    for(int i = 1; i <= k; i++)
        update(1,1,n,tin[i],tout[i],1);
    cout << seg[1] << ' ';
    for(int i = k+1; i <= n; i++)
    {
        update(1,1,n,tin[i-k],tout[i-k],-1);
        update(1,1,n,tin[i],tout[i],1);
        cout << seg[1] << ' ';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
 