/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long
#define x first
#define y second
 
using namespace std;
 
const int N = 2e5 + 5;
int a[N];
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
vector <int> v, v2, v3, v4;
 
bool ok(int val, int n){
    v.clear();
    v2.clear();
    for(int i = 1; i <= n; ++i){
        if (a[i] != val) v.push_back(a[i]);
    }
    v2 = v;
    reverse(v2.begin(), v2.end());
    return (v == v2);
}
 
void solve(){
    int n, m;
    v.clear();
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    bool f = true, fdiff = false;
    int pos;
    for(int i = 1; i <= n; ++i){
        if (a[i] != a[n - i + 1]){
            fdiff = true;
            f = false;
            pos = i;
            break;
        }
    }
    if (fdiff){
        f |= ok(a[pos], n);
        f |= ok(a[n - pos + 1], n);
    }
    if (f) cout << "yes" << endl;
    else cout << "no" << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}