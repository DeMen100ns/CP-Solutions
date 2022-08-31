#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5e4 + 5;
int a[N];
vector <int> p[N];
 
set <int> s;
 
void solve(){
    s.clear();
    int n, l, ans = 0;
    cin >> n;
    bool f = false;
    for(int i = 1; i <= n; ++i) cin >> a[i], p[a[i]].push_back(i), f |= (p[a[i]].size() >= 2), s.insert(a[i]);
    if (!f) {for(int i = 1; i <= n; ++i) p[a[i]].clear(); cout << -1 << endl; return;}
    for(int i : s){
        if (p[i].size() == 1) {p[i].clear(); continue;}
        for(int j = 0; j < p[i].size() - 1; ++j){
            int diff = p[i][j + 1] - p[i][j];
            ans = max(ans, n - diff);
        }
        p[i].clear();
    }
    cout << ans << endl;
}
 
int main(){
    int t; cin >> t;
    while (t--) solve();
}