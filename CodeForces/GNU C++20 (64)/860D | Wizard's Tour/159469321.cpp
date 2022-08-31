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
 
vector <int> a[N];
int num[N], tme;
vector <array<int, 3>> ans;
 
bool dfs(int u, int par = 0){
 vector <int> cur;
 num[u] = ++tme;
 
 for(int i : a[u]){
  if (i == par) continue;
  if (!num[i]){
   if (dfs(i, u)) cur.push_back(i);
  } else {
   //back-edge
   if (num[u] < num[i])
    cur.push_back(i);
  }
 }
 //cout << u << " " << cur.size() << endl;
 for(int i = 0; i + 1 < cur.size(); i += 2){
  ans.push_back({cur[i], u, cur[i + 1]});
 }
 if (cur.size() % 2 == 0) return true;
 if (par) ans.push_back({cur.back(), u, par});
 
 return false;
}
 
void solve()
{
    int n, m; cin >> n >> m;
 while(m--){
  int u, v; cin >> u >> v;
  a[u].push_back(v);
  a[v].push_back(u);
 }
 for(int i = 1; i <= n; ++i)
  if (!num[i]) dfs(i);
 cout << ans.size() << endl;
 for(array<int, 3> e : ans){
  cout << e[0] << " " << e[1] << " " << e[2] << endl;
 }
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1; //cin >> t;
    while (t--)
    {
        solve();
    }
}