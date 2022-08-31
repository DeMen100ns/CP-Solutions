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
 
void solve(){
    int n, m, a, b, c, d;
    cin >> n >> m >> a >> b >> c >> d;
    int ans = N;
    if (a <= c) ans = min(ans, c - a);
    else ans = min(ans, n - a + n - c);
    if (b <= d) ans = min(ans, d - b);
    else ans = min(ans, m - d + m - b);
    cout << ans << endl;
    //8 -> 10 -> 1
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
}