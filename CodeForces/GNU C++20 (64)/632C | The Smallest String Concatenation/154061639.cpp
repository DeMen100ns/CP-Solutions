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
 
string s[N];
 
bool cmp(string a, string b){
 return a + b < b + a;
}
void solve()
{
 int n; cin >> n;
 for(int i = 1; i <= n; ++i) cin >> s[i];
 sort(s + 1, s + n + 1, cmp);
 for(int i = 1; i <= n; ++i) cout << s[i];
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