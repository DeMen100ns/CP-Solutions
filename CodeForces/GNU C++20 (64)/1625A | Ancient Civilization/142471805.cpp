#include <bits/stdc++.h>
 
using namespace std;
 
int a[105], cnt[30];
 
void solve(){
    int n, l;
    cin >> n >> l;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    for(int i = 0; i < l; ++i){
        int cnt = 0;
        for(int j = 1; j <= n; ++j){
            cnt += ((a[j] >> i) & 1);
        }
        if (cnt > n / 2) ans |= (1 << i);
    } cout << ans << endl;
}
 
int main(){
    int t; cin >> t;
    while (t--) solve();
}