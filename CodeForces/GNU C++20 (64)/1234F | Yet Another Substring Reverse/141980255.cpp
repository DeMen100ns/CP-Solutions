/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = (1 << 20) + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
bool dp[N];
int dp2[N];
 
void solve(){
 string s;
    cin >> s;
    dp[0] = true;
    for(int i = 0; i < s.size(); ++i){
     int mask = 0;
     for(int j = i; j < s.size(); ++j){
      int p1 = (1 << (s[j] - 'a'));
      if (mask & p1) break;
      else mask |= p1;
      dp[mask] = true;
      dp2[mask] = __builtin_popcount(mask);
     } 
    }
    int m = (1 << 20) - 1;
    for(int i = 0; i < 20; ++i){
     for(int mask = 0; mask <= m; ++mask){
      if (mask & (1 << i)){
       dp2[mask] = max(dp2[mask], dp2[mask ^ (1 << i)]);
      }
     }
    }
    int ans = 0;
    for(int mask = 0; mask <= m; ++mask){
     if (dp[mask]){
      ans = max(ans, __builtin_popcount(mask) + dp2[mask ^ m]);
     }
    }
    cout << ans;
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