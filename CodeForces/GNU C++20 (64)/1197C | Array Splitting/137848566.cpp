#include <bits/stdc++.h>
 
#define int long double
 
using namespace std;
 
const long long N = 3e5 + 5;
int a[N], dp[N], cnt[N];
 
void solve(){
    long long n, k;
    cin >> n >> k;
    for(long long i = 1; i <= n; ++i) cin >> a[i];
    int lcost = 1e-6, rcost = 1e12 + 1;
    while (lcost + 1e-6 < rcost){
        int midcost = sqrtl(lcost * rcost);
        for(long long i = 1; i <= n; ++i){
            if (i == n || a[i + 1] - a[i] > midcost){
                dp[i] = dp[i - 1] + midcost;
                cnt[i] = cnt[i - 1] + 1;
            } else {
                dp[i] = dp[i - 1] + a[i + 1] - a[i];
                cnt[i] = cnt[i - 1];
            }
        }
        if (cnt[n] <= k) rcost = midcost;
        else lcost = midcost;
       // cout << midcost << " " << dp[n] << " " << cnt[n] << endl;
    }
    cout << abs((long long)round(dp[n] - rcost * k));
}
 
signed main(){
    solve();
}