/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 3e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
vector <int> a[N];
vector <pair<int, int>> need;
int s, t, cnt, ancestorT[N], num[N], low[N], tail[N];
stack <int> st;
 
void dfs(int u, int p = 0){
 st.push(u);
 num[u] = low[u] = ++cnt;
 for(int i : a[u]){
  if (i == p) continue;
  if (!num[i]){
   dfs(i, u);
   low[u] = min(low[u], low[i]);
  } else {
   low[u] = min(low[u], num[i]);
  }
 }
 tail[u] = ++cnt;
 if (num[u] == low[u]){
  bool f = num[u] <= num[t] && num[t] <= tail[u]; //check if u is ancestor of t in bridge-tree
  int v = 0;
  do{
   v = st.top(); st.pop();
   ancestorT[v] = f; 
  }while(u != v);
 }
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
     int u, v, type;
     cin >> u >> v >> type;
     a[u].push_back(v);
     a[v].push_back(u);
     if (type == 1){
      need.push_back({u, v});
     }
    }
    cin >> s >> t;
    dfs(s);
    for(pair<int, int> i : need){
     if (ancestorT[i.first] && ancestorT[i.second]){
      cout << "YES" << endl;
      return;
     }
    }
    cout << "NO" << endl;
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
}