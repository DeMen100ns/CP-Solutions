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
 
set <pair<int, int>> s;
 
void solve()
{
    int n, a, b, x, y, z, ans;
    cin >> n >> a >> b >> x >> y >> z;
    ans = x * n;
    //a / y > b / z -> az > by
    
    int k1 = n / a, k2 = n / b;
    int oth1 = n - k1 * a, oth2 = n - k2 * b;
    ans = min({ans, k1 * y + oth1 * x, k2 * z + oth2 * x});
 
    for(int cnt2 = 0; cnt2 * cnt2 <= 1e9 + 1; ++cnt2){
        int k2 = cnt2 * b;
        int otha = n - k2;
        int cnt1 = otha / a;
        int k1 = cnt1 * a;
        if (otha < 0) continue;
        ans = min(ans, cnt1 * y + cnt2 * z + (n - k1 - k2) * x);
    }

    swap(a, b); swap(y, z);

    for(int cnt2 = 0; cnt2 * cnt2 <= 1e9 + 1; ++cnt2){
        int k2 = cnt2 * b;
        int otha = n - k2;
        int cnt1 = otha / a;
        int k1 = cnt1 * a;
        if (otha < 0) continue;
        ans = min(ans, cnt1 * y + cnt2 * z + (n - k1 - k2) * x);
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