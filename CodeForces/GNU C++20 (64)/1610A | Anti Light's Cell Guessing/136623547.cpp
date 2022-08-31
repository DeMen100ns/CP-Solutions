/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
int a[N];
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve(){
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1){
        cout << 0 << endl;
        return;
    }
    if (min(n, m) == 1) cout << 1 << endl;
    else cout << 2 << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}