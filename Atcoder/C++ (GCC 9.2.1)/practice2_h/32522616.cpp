/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int x[N], y[N];

void solve()
{
    int n, d; cin >> n >> d;
    two_sat a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            if (abs(x[i] - x[j]) < d)
                a.add_clause(i, false, j, false);
            if (abs(x[i] - y[j]) < d)
                a.add_clause(i, false, j, true);
            if (abs(y[i] - x[j]) < d)
                a.add_clause(i, true, j, false);
            if (abs(y[i] - y[j]) < d)
                a.add_clause(i, true, j, true);
        }
    }
    if (!a.satisfiable()){
        cout << "No"; return;
    }
    cout << "Yes" << endl;
    vector <bool> ans = a.answer();
    for(int i = 1; i <= n; ++i){
        if (ans[i]) cout << x[i] << endl;
        else cout << y[i] << endl;
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