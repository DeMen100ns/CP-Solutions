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
 
int a[N], pre[N];
 
void solve()
{
    int n, x, sum = 0; cin >> n >> x;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if (i > 1) sum += abs(a[i] - a[i - 1]);
    }
    int l = min(a[1], a[n]) - 1;
    int r = max((int)0, x - max(a[1], a[n]));
    for(int i = 1; i < n; ++i){
        l = min(l, 2 * (min(a[i], a[i + 1]) - 1));
        r = min(r, max((int)0, 2 * (x - max(a[i], a[i + 1]))));
    }
    cout << sum + l + r << endl;
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