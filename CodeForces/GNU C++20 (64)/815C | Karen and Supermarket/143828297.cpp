/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
/*
Sauce : https://codeforces.com/contest/815/problem/C
 
Tag : DP tree
 
Solution : dp[i][j][state] : Cost nhỏ nhất để chọn j món trong subtree, với phiếu giảm giá hoặc không.  
 
Note : 
- Combine subtree, cái này nhìn như O(n ^ 3) nhưng thực tế nó là O(n ^ 2) (proved)
- for loop tới size của subtree, không phải tới n (Nếu không thì nó sẽ thành O(n ^ 3))
 
Complexity : O(n ^ 2)
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 5e3 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int cost[N], coupon[N], siz[N];
vector <int> a[N];
int dp[N][N][2];
 
void dfs(int u, int par = 0){
 siz[u] = 1;
 dp[u][0][0] = 0;
 dp[u][1][0] = cost[u];
 dp[u][1][1] = cost[u] - coupon[u];
 for(int i : a[u]){
  if (i == par) continue;
  dfs(i, u);
  for(int c1 = siz[u]; c1 >= 0; --c1){
   for(int c2 = siz[i]; c2 >= 0; --c2){
    dp[u][c1 + c2][1] = min(dp[u][c1 + c2][1], dp[u][c1][1] + min(dp[i][c2][0], dp[i][c2][1]));
    dp[u][c1 + c2][0] = min(dp[u][c1 + c2][0], dp[u][c1][0] + dp[i][c2][0]);
   }
  }
  siz[u] += siz[i];
 }
}
 
void solve(){
 int n, S;
    cin >> n >> S;
    for(int i = 1; i <= n; ++i){
     cin >> cost[i] >> coupon[i];
     if (i > 1){
      int v; cin >> v;
      a[v].push_back(i);
     }
     for(int j = 0; j <= n; ++j) 
      for(int k = 0; k <= 1; ++k) dp[i][j][k] = INF;
    }
    dfs(1);
    for(int i = n; i >= 0; --i){
     if (min(dp[1][i][0], dp[1][i][1]) <= S){
      cout << i;
      return;
     }
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