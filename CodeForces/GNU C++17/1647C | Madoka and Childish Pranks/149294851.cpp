/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e3 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
char c[N][N];
vector <array<int, 4>> v;
 
void solve(){
    v.clear();
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
     for(int j = 1; j <= m; ++j){
      cin >> c[i][j];
     }
    }
    if (c[1][1] == '1'){
     cout << -1 << endl;
     return;
    }
    for(int i = n; i > 1; --i){
     for(int j = m; j; --j){
      if (c[i][j] == '1'){
       v.push_back({i - 1, j, i, j});
      }
     }
    }
    for(int i = m; i; --i){
     if (c[1][i] == '1'){
      v.push_back({1, i - 1, 1, i});
     }
    }
    cout << v.size() << endl;
    for(auto i : v){
     for(int j = 0; j < 4; ++j){
      cout << i[j] << " ";
     } cout << endl;
    }
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
    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}