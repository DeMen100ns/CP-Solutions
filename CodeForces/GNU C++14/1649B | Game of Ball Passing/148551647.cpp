/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N];
 
void solve(){
    int n;
    cin >> n;
    int s = 0;
    bool f = true;
    for(int i = 1; i <= n; ++i){
     cin >> a[i];
        s += a[i];
    }
    if (s == 0){
        cout << 0 << endl;
        return;
    }
    sort(a + 1, a + n + 1);
    s -= a[n];
    s = a[n] - (s + 1);
    if (s <= 0){
        cout << 1;
    } else {
        cout << 1 + s;
    }
    cout << endl;
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