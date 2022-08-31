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
char c[30];
 
void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int k; cin >> k;
    for(int i = 1; i <= k; ++i) cin >> c[i];
    int ma = 0, cnt = 0;
    for(char ch : s){
        bool f = false;
        for(int i = 1; i <= k; ++i) f |= (c[i] == ch);
        if (f){
            ma = max(ma, cnt);
            cnt = 0;
        }
        ++cnt;
    }
    cout << ma << endl;
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