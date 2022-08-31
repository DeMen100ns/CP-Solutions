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
vector <int> v[N];
 
void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        v[i] = {a[i]};
    }
    bool g = true;
    for(int i = 2; i <= n; ++i){
        bool f = false;
        for(int val : v[i - 1]){
            if (a[i] % val == 0){
                f = true;
                v[i].push_back(val);
            } else v[i].push_back(a[i] % val);
        }
        g &= f;
 
    }
    if (g) cout << "YES" << endl;
    else cout << "NO" << endl;
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