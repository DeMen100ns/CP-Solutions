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
    int ma1 = 0, ma2 = 0;
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], ma1 = max(ma1, a[i]);
    int m; cin >> m;
    for(int i = 1; i <= m; ++i) cin >> b[i], ma2 = max(ma2, b[i]);
    if (ma1 > ma2){
        cout << "Alice" << endl << "Alice";
    }
    if (ma2 > ma1){
        cout << "Bob" << endl << "Bob";
    }
    if (ma1 == ma2){
        cout << "Alice" << endl << "Bob";
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