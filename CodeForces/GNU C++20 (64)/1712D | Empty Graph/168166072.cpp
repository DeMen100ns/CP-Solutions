/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
 
Name: 
Sauce: 
Tag: 
Sol: 
Note: 
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int N = 2e5 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
pair<int, int> a[N];
int b[N], n;
 
void change(multiset <int> &s, multiset <int> &s2, int pos, int val){
    s.erase(s.find(b[pos]));
    if (pos > 1) s2.erase(s2.find(min(b[pos - 1], b[pos])));
    if (pos < n) s2.erase(s2.find(min(b[pos], b[pos + 1])));
 
    b[pos] = val;
 
    s.insert(b[pos]);
    if (pos > 1) s2.insert(min(b[pos - 1], b[pos]));
    if (pos < n) s2.insert(min(b[pos], b[pos + 1]));   
}
 
void solve()
{
    int k; cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i].first, a[i].second = i;
    sort(a + 1, a + n + 1);
    for(int i = 1; i < k; ++i) a[i].first = MAXA;
    for(int i = 1; i <= n; ++i){
        b[a[i].second] = a[i].first;
    }
 
    multiset <int> s, s2;
    s.clear(); s2.clear();
    for(int i = 1; i < n; ++i){
        s2.insert(min(b[i], b[i + 1]));
    }
    for(int i = 1; i <= n; ++i){
        s.insert(b[i]);
    }
    int ans = -1;
    for(int i = 1; i <= n; ++i){
        int tmp = b[i];
 
        change(s, s2, i, MAXA);
 
        int tmp1 = *s.begin();
        tmp1 *= 2;
        int tmp2 = *prev(s2.end());
 
        ans = max(ans, min(tmp1, tmp2));
 
        change(s, s2, i, tmp);
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