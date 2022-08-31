/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long 
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N];
 
void solve(){
    int n, k, sum = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
    sort(a + 1, a + n + 1);
    if (sum <= k) {cout << 0 << endl; return;}
    int mi = sum - k;
    for(int i = n; i >= 2; --i){
        sum -= a[i] - a[1];
        int diff = sum - k;
        int tme = n - i + 1;
        if (diff > 0){
            tme += (diff - 1) / (tme + 1) + 1;
        }
        mi = min(mi, tme);
    }
    cout << mi << endl;
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