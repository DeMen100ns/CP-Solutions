/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
 
Name:
Sauce: 
Tag: 
Sol: 
Note: 
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N];
 
void solve()
{
    int n, k, b, s; cin >> n >> k >> b >> s;
    fill(a + 1, a + n + 1, 0);
    a[1] = b * k;
    if (s < b * k){
        cout << -1 << endl;
        return;
    }
    s -= b * k;
    for(int i = 1; i <= n && s > 0; ++i){
        int tmp = min(k - 1, s);
        a[i] += tmp;
        s -= tmp;
    }
    if (s > 0){
        cout << -1 << endl;
        return;
    }
    for(int i = 1; i <= n; ++i) cout << a[i] << " "; 
    cout << endl;
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