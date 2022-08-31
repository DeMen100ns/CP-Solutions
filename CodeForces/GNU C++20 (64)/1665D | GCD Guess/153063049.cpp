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
 
int a[N], deg[N];
 
void solve()
{
    int cur = 1, x = 0;
    for(int i = 0; i < 30; ++i){
        int p = (1 << i);
        int k = p - x;
        cout << "? " << k << " " << k + 2 * p << endl;
        int g; cin >> g;
        if (g % (p * 2) == 0){
            x |= p;
        }
       // cout << x << endl;
    }
    cout << "! " << x << endl;
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