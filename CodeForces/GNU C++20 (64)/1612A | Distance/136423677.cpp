#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
int a[N];
 
void solve(){
    int a, b;
    cin >> a >> b;
    if ((a + b) & 1){
        cout << -1 << " " << -1 << endl;
    } else {
        if (a > b){
            cout << (a + b) / 2 << " " << 0 << endl;
        } else {
            cout << 0 << " " << (a + b) / 2 << endl;
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}