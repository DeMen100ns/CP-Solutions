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
 
void solve(){
    int a[10];
    cin >> a[1] >> a[2] >> a[3];
    sort(a + 1, a + 4);
    bool f = false;
    if (a[1] == a[2]){
     if (a[3] % 2 == 0) f = true;
    }
    if (a[2] == a[3]){
     if (a[1] % 2 == 0) f = true;
    }
    if (a[1] + a[2] == a[3]) f = true;
    if (f) cout << "yes" << endl;
    else cout << "no" << endl;
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