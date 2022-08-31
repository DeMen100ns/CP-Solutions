/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N];
 
void solve()
{
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int l = 0, r = n + 1;
    while (l + 1 < r){
        int mid = (l + r) >> 1, tmp = q;
        for(int i = mid; i <= n; ++i){
            if (a[i] > tmp) --tmp;
        }
        if (tmp < 0) l = mid;
        else r = mid;
    }
    for(int i = 1; i <= n; ++i){
        if (a[i] <= q || (q > 0 && i >= r)){
            cout << 1;
            q -= (a[i] > q);
        } else cout << 0;
    } cout << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1; cin >> t;
    while (t--)
    {
        solve();
    }
}