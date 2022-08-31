/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], b[N];
pair<int, int> range[N];
set <pair<int, int>> s[N];
 
void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> b[i]; a[i] = 0;
        int l = i / (b[i] + 1) + 1, r;
        if (b[i]) r = i / b[i];
        else r = n;
        s[l].insert({r, i});
    }
    for(int i = 1; i <= n; ++i){
        auto it = s[i].begin();
        a[(*it).second] = i;
        s[i].erase(it);
        if (s[i + 1].size() < s[i].size()){
            swap(s[i], s[i + 1]);
        }
        for(pair<int, int> v : s[i]) {
            if (v.first < i + 1) continue;
            s[i + 1].insert(v);
        }
        s[i].clear();
    }
    for(int i = 1; i <= n; ++i) cout << a[i] << " ";
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