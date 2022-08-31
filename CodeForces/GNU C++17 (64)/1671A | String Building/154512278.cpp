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
 
void solve()
{
    string s; cin >> s;
    bool f = true;
    for(int i = 0; i < s.size(); ++i){
        int cnt = 0;
        if (i == 0 || s[i - 1] != s[i]) ++cnt;
        if (i == s.size() - 1 || s[i] != s[i + 1]) ++cnt;
        f &= (cnt < 2); 
    }
    if (f) cout << "yes";
    else cout << "no";
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