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

vector <int> a, b, c;

void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        a.push_back(x);
    }
    for(int i = 1; i <= m; ++i){
        int x; cin >> x;
        b.push_back(x); 
    }
    vector <int> c = convolution(a, b);
    for(int i : c){
        cout << i << " ";
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