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
 
int a[N];
 
void solve()
{
    int n, ct2 = 0, ct3 = 0; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i < n; ++i){
        ct2 += (a[i] == a[i + 1] - 2);
        ct3 += (a[i] == a[i + 1] - 3);
        if (ct3 > 1) ct2 = 3;
        if (ct3 == 1 && ct2) ct2 = 3;
        if (a[i] < a[i + 1] - 3) ct2 = 3;
    }
    if (ct2 <= 2) cout<<"yes";
    else cout<<"no";
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