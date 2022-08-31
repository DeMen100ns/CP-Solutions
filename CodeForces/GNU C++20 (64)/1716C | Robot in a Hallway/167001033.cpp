/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
 
Name: 
Sauce: 
Tag: 
Sol: 
Note: 
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[2][N], ma[2];
int dp1[2][N], dp2[2][N];
 
void solve()
{
    int n; cin >> n;
    for(int i = 0; i < 2; ++i){
        for(int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (i == 0 && j > 1) ma[0] = max(ma[0], a[i][j]) + 1;
        }
    }
 
    for(int i = 0; i < 2; ++i){
        for(int j = n; j; --j) {
            dp1[i][j] = max(dp1[i][j + 1] - 1, a[i][j] + 1);
            dp2[i][j] = max(dp2[i][j + 1] + 1, a[i][j] + 1);
            if (i) ma[0] = max(ma[0], a[i][j]) + 1;
        }
    }
 
    for(int i = 1; i <= n; ++i){
        int p = (i & 1) ^ 1;
        if (i > 1) ma[1] = max(ma[1], a[p][i]) + 1;
        ma[1] = max(ma[1], a[p ^ 1][i]) + 1;
 
        int tmp = max(ma[1], dp1[p ^ 1][i]) + n - i + 1;
        int tmp2 = dp2[p][i + 1] - (n - i - 1);
        ma[0] = min(ma[0], max(tmp, tmp2) + n - i - 1);
    }
 
    cout << ma[0] << endl;
 
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j <= n; ++j) dp1[i][j] = dp2[i][j] = 0;
        ma[i] = 0;
    }
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