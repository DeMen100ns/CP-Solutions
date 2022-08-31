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
    int n; cin >> n;
    string s; cin >> s;
    s += " ";
    vector <int> v;
    int cnt = 0;
    char last = s[0];
    for(char c : s){
        if (c == last) ++cnt;
        else{
            v.push_back(cnt);
            cnt = 1;
        }
        last = c;
    }
    int ans = 0;
    bool f = false;
    for(int i : v){
        if (i & 1){
            if (f) ans++;
            f = !f;
        } else{
            if (f){
                ans++;
            }
        }
    }
    cout << ans << endl;
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