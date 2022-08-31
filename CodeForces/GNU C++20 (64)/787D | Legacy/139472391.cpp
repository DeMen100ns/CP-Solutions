#include <bits/stdc++.h>
 
#define x first
#define y second
#define endl '\n'
#define int long long
 
using namespace std;
 
const int N = 1e5 + 5;
const int base = 311;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int INF = 1e18 + 7;
 
vector <pair<int, int>> a[8 * N];
int n, cnt;
int p[N], d[8 * N];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
 
void upd(int type, int id, int l, int r, int s, int u, int v, int val){
 if (l > v || r < u) return;
 if (l >= u && r <= v){
  if (type == 1) a[p[s]].push_back({id, val});
  else a[id + 4 * N].push_back({p[s], val});
  return;
 }
 int mid = (l + r) >> 1;
 upd(type, id << 1, l, mid, s, u, v, val);
 upd(type, id << 1 | 1, mid + 1, r, s, u, v, val); 
}
 
void build(int id, int l, int r){
 if (l > r) return;
 if (l == r){
  a[id].push_back({id + 4 * N, 0});
  p[l] = id; return;
 }
 a[id].push_back({id << 1, 0});
 a[id].push_back({id << 1 | 1, 0});
 a[(id << 1) + 4 * N].push_back({id + 4 * N, 0});
 a[(id << 1 | 1) + 4 * N].push_back({id + 4 * N, 0});
 int mid = (l + r) >> 1;
 build(id << 1, l, mid);
 build(id << 1 | 1, mid + 1, r);
}
 
void dijkstra(int s){
 q.push({0, s});
 while (!q.empty()){
  int du = q.top().x;
  int u = q.top().y;
  q.pop();
  if (du != d[u]) continue;
  for(auto i : a[u]){
   int v = i.x;
   int w = i.y;
   if (d[v] > d[u] + w){
    d[v] = d[u] + w;
    q.push({d[v], v});
   }
  }
 }
}
 
void solve(){
 int q, s;
 cin >> n >> q >> s;
 build(1,1,n);
 while (q--){
  int type, u, v, val, l, r;
  cin >> type;
  if (type == 1){
   cin >> u >> v >> val;
   upd(1, 1, 1, n, u, v, v, val);
  }
  if (type == 2){
   cin >> u >> l >> r >> val;
   upd(1, 1, 1, n, u, l, r, val);
  }
  if (type == 3){
   cin >> u >> l >> r >> val;
   upd(2, 1, 1, n, u, l, r, val);
  }
 }
 for(int i = 1; i <= 800000; ++i) d[i] = INF;
 /*for(int i = 1; i <= 4 * n; ++i){
  cout << i << " : ";
  for(auto j : a[i]){
   cout << j.x << " ";
  }
  cout << endl;
 }*/
 d[p[s]] = 0;
 dijkstra(p[s]);
 for(int i = 1; i <= n; ++i){
  if (d[p[i]] == INF) d[p[i]] = -1;
  cout << d[p[i]] << " ";
 }
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