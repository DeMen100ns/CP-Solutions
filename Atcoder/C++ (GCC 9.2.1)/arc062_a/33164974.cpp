/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int a[N];

void solve()
{
    int n; cin >> n;
    int t, a; cin >> t >> a;
    for(int i = 2; i <= n; ++i){
        int rt, ra; cin >> rt >> ra;
        int pt = (t + rt - 1) / rt;
        int pa = (a + ra - 1) / ra;
        int p = max(pt, pa);
        t = rt * p; a = ra * p;
    }
    cout << t + a;
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