/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 6e3 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], b[N], dp[N], prv[N];
vector <int> v;
 
void solve(){
    int n, m; 
    cin >> n;// >> m;
    for(int i = 1; i <= n; ++i) {
     cin >> a[i];
    } 
    cin >> m;
    for(int i = 1; i <= m; ++i) {
     cin >> b[i];
    }
    int ans = 0, idans = 0;
    for(int i = 1; i <= n; ++i){
     int ma = 0, id = 0;
     for(int j = 1; j <= m; ++j){
      if (a[i] == b[j]){
       dp[j] = max(dp[j], ma + 1);
                prv[j] = id;
      } else if (a[i] > b[j]){
       if (dp[j] > ma){
                    ma = dp[j];
                    id = j;
                }
      }
     }
    }
    for(int i = 1; i <= m; ++i){
        if (dp[i] > ans){
            ans = dp[i];
            idans = i;
        }
    }
   // for(int i = 1; i <= m; ++i) cout << prv[i] << " "; cout << endl;
    cout << ans << endl;
    for(int i = idans; i; i = prv[i]){
     v.push_back(b[i]);
    }
    reverse(v.begin(), v.end());
    for(int i : v) cout << i << " ";
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