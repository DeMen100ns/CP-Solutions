/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], d[N];
string s[N];
int cnt[26][26];
int cnt0[26], cnt1[26];
 
void solve()
{
    int n, ans = 0; cin >> n;
    memset(cnt, 0, sizeof cnt);
    memset(cnt0, 0, sizeof cnt0);
    memset(cnt1, 0, sizeof cnt1);
    for(int i = 1; i <= n; ++i){
        cin >> s[i];
        cnt[s[i][0] - 'a'][s[i][1] - 'a']++;
        cnt0[s[i][0] - 'a']++;
        cnt1[s[i][1] - 'a']++;
    }
    for(int i = 1; i <= n; ++i){
        ans += cnt0[s[i][0] - 'a'] + cnt1[s[i][1] - 'a'] - cnt[s[i][0] - 'a'][s[i][1] - 'a'] * 2;
    }
    cout << ans / 2 << endl;
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