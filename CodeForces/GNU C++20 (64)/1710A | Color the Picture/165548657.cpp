/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N];
multiset <int> sn, sm;
 
bool solve(multiset <int> s, int n){
    for(int i : s){
        if (n == 1){
            if (i > *s.begin()){
                return true;
            }
        }
        if (n > 1){
            n -= i;
        }
        if (n <= 0) return true;
    }
    //2 3 3
    //n = 9
    return false;
}
 
void solve()
{
    int n, m, k; cin >> n >> m >> k;
    sn.clear(); sm.clear();
    for(int i = 1; i <= k; ++i){
        cin >> a[i];
        if (a[i] / n >= 2) sn.insert(a[i] / n);
        if (a[i] / m >= 2) sm.insert(a[i] / m);
    }
    if (solve(sn, m) || solve(sm, n)){
        cout << "Yes" << endl;
    } else cout << "No" << endl;
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