/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
/*
Day start : 09/06/2022
To - day  : 11/06/2022
Counting : 0005
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int MOD = 998244353;
void add(int &a, int b, int mod = MOD){ a += b; while (a < 0) a += mod; while (a >= mod) a -= mod; }
int sum(int a, int b, int mod = MOD){ return add(a, b, mod), a; }
void mul(int &a, int b, int mod = MOD){ a = (a * 1LL * b) % mod; }
int prod(int a, int b, int mod = MOD){ return mul(a, b, mod), a; }
int bpow(int a, int b, int mod = MOD){ int ans = 1; while (b){ if (b & 1){ mul(ans, a, mod); } mul(a, a, mod); b >>= 1; } return ans; }
int Inv(int a, int mod = MOD){ return bpow(a, mod - 2, mod); }
int Div(int a, int b, int mod = MOD) { return prod(a, Inv(b, mod), mod); }
 
const int N = 1e6 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
vector <int> a[N];
int cnt[N];
 
void solve()
{
 int n, ans = 0; cin >> n;
 int n2 = prod(n, n);
 for(int i = 1; i <= n; ++i){
  int k; cin >> k;
  while (k--){
   int c; cin >> c;
   cnt[c]++;
   a[i].push_back(c);
  }
 }
 for(int i = 1; i <= n; ++i){
  for(int v : a[i]){
   // 1 / n * 1 / a[i].size() * k / n
   int cur = cnt[v];
   cur = Div(cur, prod(n2, a[i].size()));
   add(ans, cur);
  }
 }
 cout << ans;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1; //cin >> t;
    while (t--)
    {
        solve();
    }
}