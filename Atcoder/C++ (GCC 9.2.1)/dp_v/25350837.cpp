#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
long long n,m;
vector<long long> adj[100005];
long long dp1[100005];
long long dp2[100005];
long long MOD;
void dfs(int u,int par)
{
    dp1[u] = 1%MOD;
    long long ans = 1;
    for(auto v : adj[u])
    {
        if(v!=par)
        {
            dfs(v,u);
            ans *= dp1[v];
            ans %= MOD;
 
        }
    }
    dp1[u] = (dp1[u]+ans)%MOD;
}
void dfs2(int u,int par)
{
    dp2[u] = (dp2[u]+1)%MOD;
    long long calc = dp2[u];
 
    for(auto v : adj[u])
    {
        if(v!=par)
        {
            dp2[v] = 1%MOD;
            dp2[v] *= calc;
            dp2[v] %= MOD;
            calc *= dp1[v];
            calc %= MOD;
        }
    }
    reverse(adj[u].begin(),adj[u].end());
    calc = 1;
    for(auto v : adj[u])
    {
        if(v!=par)
        {
            dp2[v] *= calc;
            dp2[v] %= MOD;
            calc *= dp1[v];
            calc %= MOD;
        }
    }
    reverse(adj[u].begin(),adj[u].end());
    for(auto v : adj[u])
        if(v!=par) dfs2(v,u);
 
 
}
void solve()
{
    cin >> n >> MOD;
    for(int i = 1; i <= n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,1);
    dfs2(1,1);
    for(int i = 1; i <= n;i++)
    {
       // cout << dp1[i] << ' ' << dp2[i] << ' ';
        cout << (dp1[i]-1+MOD)%MOD*dp2[i]%MOD << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
 
 
 
}