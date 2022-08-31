#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
int b[N];
map <int, int> dp;
 
void solve(){
    dp.clear();
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> b[i];
    dp[0] = 1;
    int s = 1, diff = 0;
    for(int i = 1; i <= n; ++i){
        //a[i] = b[i] : dp[j] -> dp[j + b[i]]
        //pref[i] = b[i] : dp[j] -> dp[b[i]]
        int dec = dp[diff];
        dp[diff] = s;
        diff -= b[i];
        s = s * 2 - dec;
        s = (s + MOD) % MOD;
    }
    cout << s << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}