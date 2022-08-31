/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N];
 
void solve(){
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; ++i){
     cin >> a[i];
     ans += i * (n - i + 1);
    }
    for(int i = 1; i <= n; ++i){
     int cnt = 0;
     for(int j = i; j <= n; ++j){
      cnt += (a[j] == 0);
      ans += cnt;
     }
    }
    cout << ans << endl;
 
}
 
signed main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    //freopen("codeforces.inp","r",stdin);
    //freopen("codeforces.out","w",stdout);
    
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}