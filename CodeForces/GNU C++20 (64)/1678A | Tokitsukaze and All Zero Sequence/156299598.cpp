/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N];
 
void solve()
{
    int n, cnt = 0; cin >> n;
    vector <int> v;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if (a[i]) v.push_back(a[i]);
    }
    if (v.size() != n){
        cout << v.size() << endl;
        return;
    }
    bool f = false;
    for(int i = 0; i < v.size(); ++i){
        for(int j = i + 1; j < v.size(); ++j){
            f |= (v[i] == v[j]);
        }
    }
    n += (!f);
    cout << n << endl;
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