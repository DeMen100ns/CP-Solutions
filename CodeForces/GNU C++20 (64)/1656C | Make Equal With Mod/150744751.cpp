/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N];
 
void solve(){
    int n; cin >> n;
    bool f1 = false;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        f1 |= (a[i] == 1);
    }
    if (!f1){
        cout << "yes" << endl;
        return;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i < n; ++i){
        f1 &= (a[i] != a[i + 1] - 1);
    }
    if (f1) cout << "yes" << endl;
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
    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}