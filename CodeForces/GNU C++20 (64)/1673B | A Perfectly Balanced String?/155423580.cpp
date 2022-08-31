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
string s;
 
void solve()
{
    string s; cin >> s;
    bool f = true;
    for(char c = 'a'; c <= 'z'; ++c){
        for(char c2 = c + 1; c2 <= 'z'; ++c2){
            int cur = 0, mi = 0, ma = 0;
            bool f1 = false, f2 = false;
            for(int i = 0; i < s.size(); ++i){
                if (s[i] == c) ++cur, f1 = true;
                if (s[i] == c2) --cur, f2 = true;
                ma = max(ma, cur);
                mi = min(mi, cur);
            }
            
            f &= (ma - mi <= 1 || !f1 || !f2);
        }
    }
    if (f) cout << "yes";
    else cout << "no"; cout << endl;
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