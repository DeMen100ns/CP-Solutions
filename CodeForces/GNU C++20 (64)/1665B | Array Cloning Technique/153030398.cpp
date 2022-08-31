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
 
map<int, int> m;
int a[N];
 
void solve()
{
    m.clear();
    int ma = 0;
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        m[a[i]]++;
        ma = max(ma, m[a[i]]);
    }
    int p = n - ma;
    int ans = p;
    int g = ma, s = ma;
    while (s < n){
        s += g;
        ++ans;
        g <<= 1;
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
 
    int t = 1;  cin >> t;
    while (t--)
    {
        solve();
    }
}