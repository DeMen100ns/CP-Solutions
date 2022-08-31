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
 
bool checkpw2(int n){
    while (n > 1){
        if (n & 1) return false;
        n >>= 1;
    }
    return true;
}
 
void solve(){
    int n; cin >> n;
    if (checkpw2(n)){
        cout << -1 << endl;
        return;
    }
    int k = 2;
    while (k * (k + 1) / 2 <= n){
        int sum = k * (k + 1) / 2;
        if ((n - sum) % k == 0){
            cout << k << endl;
            return;
        }
        k <<= 1;
    } 
    while (n % 2 == 0){
        n >>= 1;
    }
    cout << n << endl;
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
    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}