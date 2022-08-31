/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/
 
#include <bits/stdc++.h>
 
#define int long long
#define x first
#define y second
 
using namespace std;
 
const int N = 5e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], dp[N], pref[N], p[N], fen[N], fen2[N], ma[N], n;
vector <int> v;
 
void upd(int fen[], int p, int v){
    for(int i = p; i <= n; i += i & -i){
        fen[i] = max(fen[i], v);
    }
}
 
int get(int fen[], int p){
    int res = -INF;
    for(int i = p; i; i -= i & -i){
        res = max(res, fen[i]);
    }
    return res;
}
 
void uni(){
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; ++i){
        p[i] = lower_bound(v.begin(), v.end(), pref[i]) - v.begin() + 1;
    }
}
 
void solve()
{
    int res = 0; cin >> n;
    v.clear();
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        v.push_back(pref[i]);
        fen[i] = fen2[i] = ma[i] = -INF;
    }
    uni();
    for(int i = 1; i <= n; ++i){
        dp[i] = 0;
        if (pref[i] < 0) dp[i] = -i;
        if (pref[i] > 0) dp[i] = i;
        dp[i] = max({dp[i], ma[p[i]], get(fen, p[i] - 1) + i, get(fen2, n - p[i]) - i});
        upd(fen, p[i], dp[i] - i);
        upd(fen2, n - p[i] + 1, dp[i] + i);
        ma[p[i]] = max(ma[p[i]], dp[i]);
    }
    cout << dp[n] << endl;
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