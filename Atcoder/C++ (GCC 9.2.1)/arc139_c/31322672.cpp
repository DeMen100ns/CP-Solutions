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

set <pair<int, int>> s;

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= max(n, m); i += 2){
        for(int j = min(i, n); j <= min(i + 2, n); ++j){
            for(int k = min(i, m); k <= min(i + 2, m); ++k){
                s.insert({j, k});
            }
        }
    }
    cout << s.size() << endl;
    for(auto i : s){
        cout << i.first << " " << i.second << endl;
    }
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