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
 
int a[N], b[N];
 
void solve()
{
    int n, cnt = 0; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = i;
    for(int i = 2; i <= n; ++i){
        if (a[i] == a[i - 1]) swap(b[i], b[i - 1]);
    }
    bool f = true;
    for(int i = 1; i <= n; ++i){
        f &= (b[i] != i);
    }
    if (!f){
        cout << -1 << endl; return;
    }
    for(int i = 1; i <= n; ++i) cout << b[i] << " ";
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