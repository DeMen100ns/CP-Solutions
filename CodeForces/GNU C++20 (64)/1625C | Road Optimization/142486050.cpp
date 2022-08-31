#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 500 + 5;
int dp[N][N], a[N], d[N];
 
void solve(){
    int n, l, k;
    cin >> n >> l >> k;
    for(int i = 1; i <= n; ++i) cin >> d[i]; d[n + 1] = l;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n + 1; ++i) for(int j = 1; j <= n + 1; ++j) dp[i][j] = 1e9 + 10;
    dp[1][1] = 0;
    for(int i = 2; i <= n + 1; ++i){
        for(int j = 2; j <= i; ++j){
            for(int k = 1; k < i; ++k){
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + (d[i] - d[k]) * a[k]);
            }
        }
    }
    int ans = 1e9 + 10;
    for(int i = n - k + 1; i <= n + 1; ++i) ans = min(ans, dp[n + 1][i]);
    cout << ans;
}
 
int main(){
    int t = 1;// cin >> t;
    while (t--) solve();
}