#include <bits/stdc++.h>
 
#define x first
#define y second
//#define endl '\n'
 
#define int long long
#define ii pair<int, int>
 
using namespace std;
 
const int N = 25 + 5;
const int base = 311;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int INF = 1e18 + 7;
 
int a[N][N], deg[N], n;
int dp[(1 << 21) + 5];
bool f[N], vis[N];
 
void dfs(int u){
 vis[u] = true;
 for(int i = 1; i <= n; ++i){
  if (vis[i] || a[u][i] < INF) continue;
  dfs(i);
 }
}
 
void solve(){
 int ans = 0, m;
 cin >> n >> m;
 for(int i = 1; i <= n; ++i){
  for(int j = 1; j <= n; ++j){
   if (i != j) a[i][j] = INF;
  }
 }
 for(int i = 1; i <= m; ++i){
  int u, v, w;
  cin >> u >> v >> w;
  f[u] = f[v] = true;
  a[u][v] = min(a[u][v], w);
  a[v][u] = a[u][v];
  ans += w;
  deg[u]++;
  deg[v]++;
 }
 dfs(1);
 for(int k = 1; k <= n; ++k){
  for(int i = 1; i <= n; ++i){
   for(int j = 1; j <= n; ++j){
    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
   }
  }
 }
 for(int i = 2; i <= n; ++i){
  if (a[1][i] == INF && deg[i]) {cout << -1; return;}
 }
 int mask = (1 << n) - 1;
 for(int i = 1; i <= mask; ++i) dp[i] = INF;
 for(int i = 0; i < mask; ++i){
  for(int j = 0; j < n; ++j){
   for(int k = j + 1; k < n; ++k){
    bool f1 = (i >> j) & 1, f2 = (i >> k) & 1;
    if (f1 + f2 == 0){
     int newmask = i ^ (1 << j) ^ (1 << k);
     dp[newmask] = min(dp[newmask], dp[i] + a[j + 1][k + 1]);
    }
   }
  }
 }
 int maskodd = 0;
 for(int i = 1; i <= n; ++i){
  if (deg[i] & 1) maskodd |= (1 << (i - 1));
 }
 cout << dp[maskodd] + ans;
}
 
signed main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 //freopen("QN.inp","r",stdin);
 //freopen("QN.out","w",stdout);
 
 int t = 1; //cin >> t;
 while (t--){
  solve();
 }
 
 return 0;
}