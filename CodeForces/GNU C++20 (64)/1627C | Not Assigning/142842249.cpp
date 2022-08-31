/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int ans[N];
vector <pair<int, int>> a[N];
 
void dfs(int u, int par = 0, int val = 2){
 for(auto i : a[u]){
  int v = i.first, id = i.second;
  if (v == par) continue;
  ans[id] = val;
  if (val == 2) val = 3;
  else val = 2;
  dfs(v, u, val);
 }
}
 
void solve(){
 int n;
 cin >> n;
 for(int i = 1; i <= n; ++i) a[i].clear();
 for(int i = 1; i < n; ++i){
  int u, v;
  cin >> u >> v;
  a[u].push_back({v, i});
  a[v].push_back({u, i});
 }    
 bool f = true;
 for(int i = 1; i <= n; ++i){
  f &= (a[i].size() <= 2);
 }
 if (!f){cout << -1 << endl; return;}
 dfs(1);
 for(int i = 1; i <= n - 1; ++i){
  cout << ans[i] << " ";
 } cout << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    //freopen("codeforces.inp","r",stdin);
    //freopen("codeforces.out","w",stdout);
    
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}