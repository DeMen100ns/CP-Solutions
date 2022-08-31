/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], d[N];
 
void solve()
{
    int n, k, ans = 0; cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int p = 30; p >= 0; --p){
        int ct = 0;
        for(int i = 1; i <= n; ++i){
            ct += ((a[i] >> p) & 1);
        }
        int g = n - ct;
        if (g <= k){
            k -= g;
            ans |= (1 << p);
        }
    }
    cout << ans << endl;
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