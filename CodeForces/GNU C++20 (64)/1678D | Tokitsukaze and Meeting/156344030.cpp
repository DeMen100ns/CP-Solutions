/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int ans[N], ans2[N], ct[N];
bool f[N];
 
void solve()
{
    int n, m;
    cin >> n >> m;
    string s; cin >> s; s = " " + s;
 
    fill(f, f + m + 1, false);
    fill(ct, ct + n * m + 1, 0);
 
    int cnt = 0;
 
    for(int i = 1; i <= n * m; ++i){
        if (s[i] == '1' && !f[i % m]){
            ++cnt;
            f[i % m] = true;
        }
        ans2[i] = 0;
        ans[i] = cnt;
    }
 
    //for(int i = 1; i <= n * m; ++i) cout << ans[i] << " "; cout << endl;
 
    for(int i = 1; i <= m; ++i){
        ct[1] += (s[i] - '0');
        ans2[i] = (ct[1] > 0);
    }
 
    for(int i = 2; i + m - 1 <= n * m; ++i){
        ct[i] = ct[i - 1] + s[i + m - 1] - s[i - 1];
    }
 
    for(int i = m + 1; i <= n * m; ++i){
        ans2[i] = ans2[i - m] + (ct[i - m + 1] > 0);
    }
 
    for(int i = 1; i <= n * m; ++i) cout << ans[i] + ans2[i] << " "; cout << endl;
 
    //1
 
    //1 1
 
    //0 1
    //1
 
    //0 0
    //1 1
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