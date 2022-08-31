#include <bits/stdc++.h>
 
#define x first
#define y second
#define endl '\n'
 
#define int long long
#define ll long long
#define ii pair<int, int>
 
using namespace std;
 
const int N = 2e6 + 5;
const int base = 311;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const long long INF = 1e18 + 7;
 
ll dec(ll x, ll y, int mod = MOD) {return (x-y+mod)%mod;}
ll add(ll x, ll y, int mod = MOD) {return (x + y) % mod;}
ll mul(ll x, ll y, int mod = MOD) {return ((x%mod) * (y%mod)) % mod;}
ll bpow(ll x, ll y, int mod = MOD) {ll res = 1; while (y) {if (y & 1) res = mul(res, x, mod); x = mul(x, x, mod); y >>= 1;} return res;}
ll ModInverse(ll x, int mod = MOD) {return bpow(x, mod - 2, mod);}
ll Div(ll x, ll y, int mod = MOD) {return mul(x, ModInverse(y, mod), mod);}
bool GetBit(int val, int num) {return ((val>>num) & 1);}
 
int a[N], gt[N];
 
int C(int k, int n){
 return Div(gt[n], mul(gt[k], gt[n - k]));
}
 
int A(int k, int n){
 return Div(gt[n], gt[n - k]);
}
 
int f(int n, int k){
 if (n == k) return 1;
 return mul(k, bpow(n, n - k - 1));
}
 
void solve(){
 gt[0] = 1;
 for(int i = 1; i <= N - 3; ++i) gt[i] = mul(gt[i - 1], i);
 int n, m, a, b;
 cin >> n >> m >> a >> b;
 int res = 0;
 for(int i = 1; i < n; ++i){
  //C(i - 1, m - 1)
  //A(i - 1, n - 2)
  //m ^ (n - i - 1)
  //T(n, i + 1) = (i + 1) * n ^ (n - (i + 1) - 1)
  if (i > m) break;
  int ans = C(i - 1, m - 1);
  ans = mul(ans, A(i - 1, n - 2));
  ans = mul(ans, bpow(m, n - i - 1));
  ans = mul(ans, f(n, i + 1));
  res = add(res, ans);
  //cout << C(i - 1, m - 1) << " " << A(i - 1, n - 2) << " ";
  //cout << bpow(m, n - i - 1) << " " << f(n, i + 1) << endl;
  //cout << ans << endl;
 }
 cout << res;
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