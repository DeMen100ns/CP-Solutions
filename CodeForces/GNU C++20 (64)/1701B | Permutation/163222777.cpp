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
 
bool f[N];
 
void solve()
{
    int n; cin >> n;
    cout << 2 << endl;
    fill(f + 1, f + n + 1, 0);
    for(int i = 1; i <= n; ++i){
        if (f[i]) continue;
        int u = i;
        while (u <= n){
            f[u] = true;
            cout << u << " ";
            u *= 2;
        }
    }
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