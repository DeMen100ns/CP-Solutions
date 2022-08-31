/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
/*
Day start : 09/06/2022
To - day  : 11/06/2022
Counting : 0005
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int MOD = 998244353;
void add(int &a, int b, int mod = MOD){ a += b; while (a < 0) a += mod; while (a >= mod) a -= mod; }
int sum(int a, int b, int mod = MOD){ return add(a, b, mod), a; }
void mul(int &a, int b, int mod = MOD){ a = (a * 1LL * b) % mod; }
int prod(int a, int b, int mod = MOD){ return mul(a, b, mod), a; }
int bpow(int a, int b, int mod = MOD){ int ans = 1; while (b){ if (b & 1){ mul(ans, a, mod); } mul(a, a, mod); b >>= 1; } return ans; }
int Inv(int a, int mod = MOD){ return bpow(a, mod - 2, mod); }
int Div(int a, int b, int mod = MOD) { return prod(a, Inv(b, mod), mod); }
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
vector <int> a[N], b[N], node;
int d[N], dp[N];
 
void bfs(int n){
 queue<int> q; q.push(1);
 node = {1};
 while (!q.empty()){
  int u = q.front(); q.pop();
  for(int i : a[u]){
   if (i != 1 && !d[i]){
    d[i] = d[u] + 1;
    q.push(i);
    node.push_back(i);
   }
  }
 }
}
 
void solve()
{
 int n, m; cin >> n >> m;
 for(int i = 1; i <= n; ++i){
  a[i].clear(); b[i].clear();
  d[i] = dp[i] = 0;
 } node.clear();
 for(int i = 1; i <= m; ++i){
  int u, v; cin >> u >> v;
  a[u].push_back(v);
  b[v].push_back(u);
 }
 bfs(n);
 for(int i = 1; i <= n; ++i){
  dp[i] = d[i];
  for(int v : a[i]) 
   dp[i] = min(dp[i], d[v]);
 }
 reverse(node.begin(), node.end());
 for(int u : node){
  for(int i : b[u]) 
   if (d[i] < d[u]) dp[i] = min(dp[i], dp[u]);
 }
 for(int i = 1; i <= n; ++i) cout << dp[i] << " "; cout << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1; cin >> t;
    while (t--)
    {
        solve();
    }
}