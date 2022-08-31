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
 
int a[N], d[N];
set <int> s1, s2;
 
void solve()
{
    int n, k, ans = 0; cin >> n;
    s1.clear(); s2.clear();
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i += 2){
        s1.insert(a[i] & 1);
    }
    for(int i = 2; i <= n; i += 2){
        s2.insert(a[i] & 1);
    }
    if (s1.size() == 1 && s2.size() == 1){
        cout << "yes" << endl;
    } else cout << "no" << endl;
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