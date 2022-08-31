#include <bits/stdc++.h>
 
#define x first
#define y second
#define endl '\n'
 
#define int long long
#define ii pair<int, int>
 
using namespace std;
 
const int N = 2e5 + 5;
const int base = 311;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const long long INF = 1e18 + 7;
 
int a[N], b[N], c[N], d[N];
 
int S(ii a, ii b, ii c){
 return abs((b.x - a.x) * (a.y + b.y) + (c.x - b.x) * (b.y + c.y) + (a.x - c.x) * (c.y + a.y));
}
 
void solve(){
 int w, h, n, m, n1, m1;
 cin >> w >> h;
 cin >> n;
 for(int i = 1; i <= n; ++i) cin >> a[i];
 cin >> n1;
 for(int i = 1; i <= n1; ++i) cin >> b[i];
 cin >> m;
 for(int i = 1; i <= m; ++i) cin >> c[i];
 cin >> m1;
 for(int i = 1; i <= m1; ++i) cin >> d[i];
 int ans = 0;
 for(int i = 1; i <= n; ++i){
  ans = max(ans, S({b[1], h}, {b[n1], h}, {a[i], 0}));
  ans = max(ans, S({0, c[1]}, {0, c[m]}, {a[i], 0}));
  ans = max(ans, S({w, d[1]}, {w, d[m1]}, {a[i], 0}));
 }
 for(int i = 1; i <= n1; ++i){
  ans = max(ans, S({a[1], 0}, {a[n], 0}, {b[i], h}));
  ans = max(ans, S({0, c[1]}, {0, c[m]}, {b[i], h}));
  ans = max(ans, S({w, d[1]}, {w, d[m1]}, {b[i], h}));
 }
 for(int i = 1; i <= m; ++i){
  ans = max(ans, S({b[1], h}, {b[n1], h}, {0, c[i]}));
  ans = max(ans, S({a[1], 0}, {a[n], 0}, {0, c[i]}));
  ans = max(ans, S({w, d[1]}, {w, d[m1]}, {0, c[i]}));
 }
 for(int i = 1; i <= m1; ++i){
  ans = max(ans, S({b[1], h}, {b[n1], h}, {w, d[i]}));
  ans = max(ans, S({0, c[1]}, {0, c[m]}, {w, d[i]}));
  ans = max(ans, S({a[1], 0}, {a[n], 0}, {w, d[i]}));
 }
 cout << ans << endl;
}
 
signed main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 //freopen("QN.inp","r",stdin);
 //freopen("QN.out","w",stdout);
 
 int t = 1; cin >> t;
 while (t--){
  solve();
 }
 
 return 0;
}