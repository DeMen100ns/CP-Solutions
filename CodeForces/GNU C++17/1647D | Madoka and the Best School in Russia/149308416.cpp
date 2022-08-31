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
    int d, n, ctd = 0, ct = 0;
    cin >> n >> d;
    if (n % (d * d) != 0) ++ct;
    while (n % d == 0){
        ctd++;
        n /= d;
    }
    if (ctd >= 2){
        ++ct;
        for(int i = 2; i * i <= n; ++i){
            if (n % i == 0){
                ++ct;
                break;
            }
        }
    }
    if (ctd >= 3){
        for(int i = 2; i * i <= d; ++i){
            if (d % i == 0){
                if (i * n % d != 0 || d / i * n % d != 0 || ctd >= 4){
                    ++ct;
                    break;
                }
            }
        }
    }
    if (ct >= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
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