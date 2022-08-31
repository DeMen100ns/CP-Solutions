/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
void solve(){
    int n; cin >> n;
    //1 3 9 
    int cur = 1;
    for(int i = 1; i < n; ++i){
     cur *= 3;
     if (cur > MAXA) break;
    }
    if (cur <= MAXA){
     cout << "YES" << endl;
     cur = 1;
     for(int i = 1; i <= n; ++i){
      cout << cur << " ";
      cur *= 3;
     } cout << endl;
    } else {
     cout << "NO" << endl;
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