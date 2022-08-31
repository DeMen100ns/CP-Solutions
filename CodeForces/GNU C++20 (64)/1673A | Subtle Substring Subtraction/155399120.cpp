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
 
void solve()
{
    string s; cin >> s;
    int sum = 0;
    for(char c : s){
        sum += (c - 'a' + 1);
    }
    if (s.size() & 1){
        sum -= 2 * (min(s[0], s.back()) - 'a' + 1);
    }
    if (sum >= 0){
        cout << "Alice " << sum << endl;
    } else {
        cout << "Bob " << -sum << endl;
    }
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