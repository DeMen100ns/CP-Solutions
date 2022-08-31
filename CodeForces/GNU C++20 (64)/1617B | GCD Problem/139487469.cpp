#include <bits/stdc++.h>
 
#define x first
#define y second
#define endl '\n'
 
#define int long long
#define ii pair<int, int>
 
using namespace std;
 
const int N = 4e5 + 5;
const int base = 311;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int INF = 1e18 + 7;
 
vector <int> v, p[N];
ii a[N];
int dp[N];
 
void solve(){
 int n;
 cin >> n;
 --n;
 if (n & 1){
  cout << n / 2 << " " << n / 2 + 1 << " " << 1;
 } else {
  //11 = 4 + 6 + 1
  int l = n / 2; 
  int r = l;
  while (__gcd(l, r) > 1){
   --l;
   ++r;
  }
  cout << l << " " << r << " " << 1;
 }
 cout << endl;
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