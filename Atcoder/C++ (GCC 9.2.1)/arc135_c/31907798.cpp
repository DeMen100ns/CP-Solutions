/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 3e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int a[N], cnt[30][2];

void solve()
{
    int n, sum = 0; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        for(int b = 0; b < 30; ++b){
            if ((a[i] >> b) & 1) cnt[b][1]++;
            else cnt[b][0]++;
        }
        sum += a[i];
    }
    int ma = sum;
    for(int i = 1; i <= n; ++i){
        int sum = 0;

        for(int b = 0; b < 30; ++b){
            if ((a[i] >> b) & 1){
                sum += cnt[b][0] * (1 << b);
            } else {
                sum += cnt[b][1] * (1 << b);
            }
        }

        ma = max(ma, sum);
    }
    cout << ma;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);

    int t = 1; // cin >> t;
    while (t--)
    {
        solve();
    }
}