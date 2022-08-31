/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int cnt[N];

void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int x, y; cin >> x >> y;
        cnt[x]++; cnt[y]++;
    }
    bool f = true;
    for(int i = 1; i <= n; ++i){
        f &= (cnt[i] % 2 == 0);
    }
    if (f) cout << "YES";
    else cout << "NO";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);

    int t = 1; //cin >> t;
    while (t--)
    {
        solve();
    }
}