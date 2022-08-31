/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
//#define int long long
#define x first
#define y second
 
using namespace std;
 
const int N = 2e5 + 5;
int a[N], b[N], c[N], d[N];
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i] >> b[i];
    }
    int l = 0, r = n + 1;
    while (l + 1 < r){
        int mid = (l + r) >> 1;
        int cur = 0;
        for(int i = 1; i <= n; ++i){
            if (b[i] >= cur && a[i] >= mid - cur - 1){
                cur++;
            }
        }
        if (cur >= mid) l = mid;
        else r = mid;
    }
    cout << l << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}