/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], b[N];
 
void solve()
{
    int n, m; cin >> n >> m;
    if (n > m) swap(n, m);
    if (n == m || n + 1 == m){
        cout << n + m - 2 << endl;
        return;
    }
    if (n == 1){
        cout << -1 << endl;
        return;
    }
    int s = m - n - 1;
    int k = 2 * n - 1;
    k += s + ((s + 1) / 2) * 2;
    cout << k << endl;
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