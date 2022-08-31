/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N];
 
void solve(){
    int n;
    cin >> n;
    int ans = n;
    for(int i = 1; i <= n; ++i){
     cin >> a[i];
    }
    int l = n, r = 1;
    for(int i = 1; i <= n; ++i){
        if (a[i] == 0){
            l = i - 1;
            break;
        }
    }
    for(int i = n; i; --i){
        if (a[i] == 0){
            r = i + 1;
            break;
        }
    }
    if (l >= r){
        cout << 0;
    } else {
        cout << r - l;
    }cout << endl;
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
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}