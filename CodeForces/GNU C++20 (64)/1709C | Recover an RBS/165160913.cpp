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
 
int a[N], b[N], pre[N];
 
void solve()
{
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    int ko = n / 2, kc = n / 2;
    for(int i = 1; i <= n; ++i){
        if (s[i] == '(') a[i] = 1, --ko;
        if (s[i] == ')') a[i] = -1, --kc;
    }
    if (min(ko, kc) == 0){
        cout << "YES" << endl;
        return;
    }
    int ct = 0, mi = n + n + n;
    for(int i = 1; i <= n; ++i){
        if (s[i] == '?'){
            ++ct;
            if (ct < ko) b[i] = 1;
            if (ct == ko) b[i] = -1;
            if (ct == ko + 1) b[i] = 1;
            if (ct > ko + 1) b[i] = -1;
        }
        else b[i] = a[i];
        pre[i] = pre[i - 1] + b[i];
        mi = min(mi, pre[i]);
    }
    if (mi >= 0) cout << "NO";
    else cout << "YES";
    cout << endl;
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