/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long

using namespace std;
using namespace atcoder;

const int N = 5e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

fenwick_tree<int> fen(N);

void solve()
{
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        fen.add(i, x);
    }
    while (q--){
        int type, u, v; cin >> type >> u >> v;
        if (type == 0){
            fen.add(u, v);
        } else {
            cout << fen.sum(u, v) << endl;
        }
    }
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