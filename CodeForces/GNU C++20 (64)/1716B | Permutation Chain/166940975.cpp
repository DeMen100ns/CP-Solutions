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
 
void solve()
{
    int n; cin >> n;
 
    cout << n << endl;
    vector <int> p;
    for(int i = 1; i <= n; ++i) p.push_back(i);
    for(int i = 1; i <= n; ++i){
        for(int j : p) cout << j << " ";
        cout << endl;
        if (i < n) swap(p[i], p[i - 1]);
    }
    // 1 2 3 4
    // 2 1 3 4
    // 
    // 3 4 2 1
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