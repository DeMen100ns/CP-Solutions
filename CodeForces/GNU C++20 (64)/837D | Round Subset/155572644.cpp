/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 200 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N];
int dp[N][27 * N];
bool f[N][27 * N];
 
void solve()
{
 int n, k; cin >> n >> k;
    f[0][0] = true;
    for(int id = 1; id <= n; ++id){
  int x; cin >> x;
  int p2 = 0, p5 = 0;
  while (x % 2 == 0){
   p2++;
   x /= 2;
  }
  while (x % 5 == 0){
   p5++;
   x /= 5;
  }
  for(int c = k; c; --c){
   for(int j = 26 * id; j >= p5; --j){
    if (f[c - 1][j - p5]) {
                    dp[c][j] = max(dp[c][j], dp[c - 1][j - p5] + p2);
                    f[c][j] = true;
                }
   }
  }
 }
 int ans = 0;
 for(int c = 1; c <= 26 * n; ++c){
  ans = max(ans, min(c, dp[k][c]));
 } 
 cout << ans;
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