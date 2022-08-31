#include <bits/stdc++.h>
 
#define int unsigned long long
 
using namespace std;
 
const int N = 2e5 + 5;
int a[N];
 
int sum(int l, int r){
    int s = r * (r + 1) / 2;
    s -= l * (l - 1) / 2;
   // cout << l << " " << r << endl;
    return s;
}
 
void solve(){
    int k, x;
    cin >> k >> x;
    int l = 0, r = 2 * k - 1;
    while (l + 1 < r){
        int mid = (l + r) / 2;
        int s = 0;
        int m = mid;
        //cout << "------------" << endl;
        //cout << m << endl;
        if (mid > k){
            s = sum(1, k);
            mid -= k;
            s += sum(k - 1 - mid + 1, k - 1);
        } else {
            s = sum(1, mid);
        }
        //cout << m << " " << s << endl;
        if (s >= x) r = m;
        else l = m;
    }
    cout << r << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}