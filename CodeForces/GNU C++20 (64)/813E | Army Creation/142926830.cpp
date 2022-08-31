/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
/*
Problem : Army Creation - Codeforces
Sauce : https://codeforces.com/contest/813/problem/E
 
Tag : 
 
Solution : Binary Lifting, Segment Tree
 
Note : -
 
Complexity :
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], last[N][20], lastk[N];
vector <int> seg[4 * N];
vector <int> v[N];
 
int getp(int u, int k){
 for(int p = 18; p >= 0; --p){
  if (k >= (1 << p)){
   u = last[u][p];
   k -= (1 << p);
  }
 }
 return u;
}
 
void build(int id, int l, int r){
 if (l == r){
  seg[id].push_back(lastk[l]);
  return;
 }
 int mid = (l + r) >> 1;
 build(id << 1, l, mid);
 build(id << 1 | 1, mid + 1, r);
 merge(seg[id << 1].begin(), seg[id << 1].end(), 
  seg[id << 1 | 1].begin(), seg[id << 1 | 1].end(), back_inserter(seg[id]));
}
 
int get(int id, int l, int r, int u, int v){
 if (l > v || r < u) return 0;
 if (l >= u && r <= v){
  int k = lower_bound(seg[id].begin(), seg[id].end(), u) - seg[id].begin();
  return k;
 }
 int mid = (l + r) >> 1;
 int v1 = get(id << 1, l, mid, u, v);
 int v2 = get(id << 1 | 1, mid + 1, r, u, v);
 return v1 + v2;
}
 
void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
     cin >> a[i];
     v[a[i]].push_back(i);
    }
    for(int i = 1; i <= n; ++i){
     int k = lower_bound(v[a[i]].begin(), v[a[i]].end(), i) - v[a[i]].begin();
     if (k == 0) last[i][0] = 0;
     else last[i][0] = v[a[i]][k - 1];
     for(int j = 1; j <= 18; ++j){
      last[i][j] = last[last[i][j - 1]][j - 1];
     }
    } 
    for(int i = 1; i <= n; ++i){
     lastk[i] = getp(i, k);
    } 
    build(1, 1, n);
    int q; cin >> q;
    int last = 0;
    while (q--){
     int l, r;
     cin >> l >> r;
     l = (l + last) % n + 1;
     r = (r + last) % n + 1;
     if (l > r) swap(l, r);
     int ans = get(1, 1, n, l, r);
     cout << ans << endl;
     last = ans;
    }
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