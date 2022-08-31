#include <bits/stdc++.h>
 
#define x first
#define y second
#define endl '\n'
 
#define int long long
#define ii pair<int, int>
 
using namespace std;
 
const int N = 5e5 + 5;
const int base = 311;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const long long INF = 1e18 + 7;
 
int a[N], type[N], x[N], y[N], k[N], d[N];
 
void solve(){
 int q, n = 0;
 cin >> q;
 for(int i = 1; i <= q; ++i){
  cin >> type[i];
  cin >> x[i];
  if (type[i] == 2) cin >> y[i], k[i] = n;
  else {
   a[++n] = x[i];
   k[i] = n;
  }
 }
 for(int i = 1; i <= N - 4; ++i) d[i] = i;
 for(int i = q; i >= 1; --i){
  if (type[i] == 1){
   a[k[i]] = d[a[k[i]]];
  } else {
   d[x[i]] = d[y[i]];
  }
 }
 for(int i = 1; i <= n; ++i) cout << a[i] << " ";
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