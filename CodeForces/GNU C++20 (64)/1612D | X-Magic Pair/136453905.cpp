#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
int a[N];
 
int sum(int l, int r){
    int s = r * (r + 1) / 2;
    s -= l * (l - 1) / 2;
    return s;
}
 
void solve(){
    int a, b, x;
    cin >> a >> b >> x;
    if (x > max(a,b)){
        cout << "NO" << endl;
        return;
    }
    if (x == a || x == b){
        cout << "YES" << endl;
        return;
    }
    if (a < b) swap(a,b);
    while (a){
        if (x == a || x == b){
            cout << "YES" << endl;
            return;
        }
        if (b == 0){
            cout << "NO" << endl;
            return;
        }
        if (x < b){
            int cd = a % b;
            a = b;
            b = cd;
        }
        else if (x > b){
            if (x > a || x % b != a % b){
                cout << "NO" << endl;
            } else cout << "YES" << endl;
            return;
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}