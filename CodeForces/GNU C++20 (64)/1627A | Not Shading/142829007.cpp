/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
char a[55][55];
 
void solve(){
 int n, m, r, c;
    cin >> n >> m >> r >> c;
    bool f = false;
    for(int i = 1; i <= n; ++i){
     for(int j = 1; j <= m; ++j){
      cin >> a[i][j];
      f |= (a[i][j] == 'B');
     }
    }
    if (!f){
     cout << -1 << endl;
     return;
    }
    if (a[r][c] == 'B'){
     cout << 0 << endl;
     return;
    }
    for(int i = 1; i <= n; ++i){
     if (a[i][c] == 'B'){
      cout << 1 << endl;
      return;
     }
    }
    for(int j = 1; j <= m; ++j){
     if (a[r][j] == 'B'){
      cout << 1 << endl;
      return;
     }
    }
    cout << 2 << endl;
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