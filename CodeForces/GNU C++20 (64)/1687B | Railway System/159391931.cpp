/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int MOD = 1e9 + 7;
void add(int &a, int b, int mod = MOD){ a += b; while (a < 0) a += mod; while (a >= mod) a -= mod; }
int sum(int a, int b, int mod = MOD){ return add(a, b, mod), a; }
void mul(int &a, int b, int mod = MOD){ a = (a * 1LL * b) % mod; }
int prod(int a, int b, int mod = MOD){ return mul(a, b, mod), a; }
int bpow(int a, int b, int mod = MOD){ int ans = 1; while (b){ if (b & 1){ mul(ans, a, mod); } mul(a, a, mod); b >>= 1; } return ans; }
int Inv(int a, int mod = MOD){ return bpow(a, mod - 2, mod); }
int Div(int a, int b, int mod = MOD) { return prod(a, Inv(b, mod), mod); }
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
vector <pair<int, int>> e;
 
void solve()
{
    int n, m; cin >> n >> m;
 string s = "";
 for(int i = 1; i <= m; ++i) s += '0';
 for(int i = 0; i < m; ++i){
  s[i] = '1';
  cout << "? " << s << endl;
  int v; cin >> v;
  e.push_back({v, i + 1});
  s[i] = '0';
 }
 sort(e.begin(), e.end());
 int cur = 0;
 for(auto u : e){
  s[u.second - 1] = '1';
  cout << "? " << s << endl;
  int v; cin >> v;
  if (cur + u.first != v){
   s[u.second - 1] = '0';
  } else cur = v;
 }
 cout << "! " << cur << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1;// cin >> t;
    while (t--)
    {
        solve();
    }
}