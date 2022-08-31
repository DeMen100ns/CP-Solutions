/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int c[N], sub[N];
vector <int> a[N];
bool f[N];
int dp[21][2], ans = 0;
 
void dfs_precal(int u, int par = 0){
 sub[u] = 1;
 for(int i : a[u]){
  if (i == par || f[i]) continue;
  dfs_precal(i, u);
  sub[u] += sub[i];
 }
}
 
int find_centroid(int u, int sz, int par = 0){
 for(int i : a[u]){
  if (i == par || f[i]) continue;
  if (sub[i] > sz / 2) 
   return find_centroid(i, sz, u);
 }
 return u;
}
 
void dfs_upd(int u, int par, int v){
 for(int i = 0; i < 20; ++i){
  dp[i][v >> i & 1]++;
 }
 for(int i : a[u]){
  if (i == par || f[i]) continue; 
  dfs_upd(i, u, v ^ c[i]);
 }
}
 
void dfs_cal(int u, int par, int v){
 for(int i = 0; i < 20; ++i){
  ans += dp[i][v >> i & 1 ^ 1] * (1 << i);
 }
 for(int i : a[u]){
  if (i == par || f[i]) continue;
  dfs_cal(i, u, v ^ c[i]);
  }
}
 
void dfs_centroid(int u){
 dfs_precal(u);
 int C = find_centroid(u, sub[u]);
 
 for(int i = 0; i < 20; ++i){
  dp[i][c[C] >> i & 1]++;
 }
 
 ans += c[C];
 
 for(int i : a[C]){
  if (f[i]) continue;
  dfs_cal(i, C, c[i]);
  dfs_upd(i, C, c[C] ^ c[i]);
 }
 
 memset(dp, 0, sizeof dp);
 
 f[C] = true;
 for(int i : a[C]){
  if (f[i]) continue;
  dfs_centroid(i);
 }
}
 
void solve(){
 int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> c[i];
    for(int i = 1; i < n; ++i){
     int u, v;
     cin >> u >> v;
     a[u].push_back(v);
     a[v].push_back(u);
    }
    dfs_centroid(1);
    cout << ans;
}
 
signed main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    //freopen("codeforces.inp","r",stdin);
    //freopen("codeforces.out","w",stdout);
    
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}