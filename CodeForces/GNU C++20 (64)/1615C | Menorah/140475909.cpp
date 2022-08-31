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
 
bool a[N], b[N];
 
void solve(){
 int n; char c;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> c;
        a[i] = c - '0';
    }
    for(int i = 1; i <= n; ++i){
        cin >> c;
        b[i] = c - '0';
    }
    bool f = false, f2 = false;
    int cntt0 = 0, cntt1 = 0, cntf0 = 0, cntf1 = 0;
    for(int i = 1; i <= n; ++i){
        f |= (a[i] & b[i]);
        f2 |= ((!a[i]) & b[i]);
        if (a[i] == 1){
            if (b[i] == 0) cntf1++;
            else cntt1++;
        } else {
            if (b[i] == 0) cntt0++;
            else cntf0++;
        }
    }
    int ans = n + 1;
    if (cntf0 == cntf1){
        ans = min(ans, cntf0 + cntf1);
    }
    if (cntt1 - cntt0 == 1){
        ans = min(ans, cntt1 + cntt0);
    }
    if (ans == n + 1) ans = -1;
    cout << ans << endl;
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