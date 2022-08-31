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
 
int ans[N];
 
void solve()
{
    int n, k; string s;
    cin >> n >> k;
    cin >> s;
    if (k & 1){
        for(int i = 0; i < n; ++i){
            if (s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
    }
    fill(ans, ans + n, 0);
    for(int i = 0; i < n; ++i){
        if (k > 0 && s[i] == '0'){
            s[i] = '1';
            ans[i]++;
            --k;
        }
    }
    ans[n - 1] += k;
    if (k & 1) s[n - 1] = '0';
    cout << s << endl;
    for(int i = 0; i < n; ++i){
        cout << ans[i] << " ";
    } cout << endl;
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