/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>
#include <atcoder/string>

using namespace std;
using namespace atcoder;

const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

void solve()
{
    string s; cin >> s;
    vector <int> sa = suffix_array(s);
    vector <int> lcp = lcp_array(s, sa);
    long long ans = 1LL * s.size() * (s.size() + 1) / 2;
    for (int x : lcp) ans -= x;
    cout << ans;
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