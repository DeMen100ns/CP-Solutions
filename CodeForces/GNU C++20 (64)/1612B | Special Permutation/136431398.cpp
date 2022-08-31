#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
int a[N];
 
void solve(){
    vector <int> v;
    set <int> s;
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; ++i) s.insert(i);
    int cnt = 0, i = n + 1;
    while (cnt < n / 2 - 1){
        i--;
        if (i == b) continue;
        cnt++;
        v.push_back(i);
        s.erase(i);
    }
    if (a >= i){
        cout << -1 << endl;
        return;
    } else {
        v.push_back(a);
        s.erase(a);
    }
    int ma = *prev(s.end());
    if (ma == b){
        for(int i : v) cout << i << " ";
        for(int i : s) cout << i << " ";
    } else {
        cout << -1;
    }
    cout << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}