/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5e6 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
bool f[N];
int dp[N], cnt[N];
 
void solve()
{
    int n, m, mi = N; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x; f[x] = true;
        mi = min(mi, x);
    }
    for(int i = 1; i <= m; ++i){
        dp[i] = i;
        if (f[i]) cnt[i] = 1;
    }
    int ans = m + 1, p = m;
    for(int i = m; i; --i){
        for(int j = min((long long)m + 1, (long long)i * i); j <= m; j += i){
            if (f[j]) cnt[dp[j]]--;
            dp[j] = min(dp[j], dp[j / i]);
            if (f[j]) cnt[dp[j]]++;
        }
        while (!cnt[p]) --p;
        if (i <= mi) ans = min(ans, p - i);
    }
    cout << ans << endl;
 
    for(int i = 1; i <= m; ++i) f[i] = cnt[i] = false;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1; cin >> t;
    while (t--)
    {
        solve();
    }
}