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
 
multiset <int> s;
int n, m;
 
int dis(int i, int j){
 return max({i - 1 + j - 1, i - 1 + m - j, n - i + j - 1, n - i + m - j});
}
 
void solve(){
    cin >> n >> m;
    s.clear();
    for(int i = 1; i <= n; ++i){
     for(int j = 1; j <= m; ++j){
      s.insert(dis(i, j));
     }
    }
    for(int i : s){
     cout << i << " ";
    } cout << endl;
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