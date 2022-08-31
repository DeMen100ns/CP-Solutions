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
 
int a[N], deg[N];
 
void solve()
{
    vector <int> v = {1};
    multiset<int> s;
    int n; cin >> n;
    fill(deg + 1, deg + n + 1, 0);
    for(int i = 1; i < n; ++i){
        int x; cin >> x;
        deg[x]++;
    }
    for(int i = 1; i <= n; ++i){
        if (deg[i]) v.push_back(deg[i]);
    }
    sort(v.begin(), v.end(), greater<int>());
    int c = v.size();
    int ans = c;
    for(int i = 0; i < v.size(); ++i){
        int g = i + v[i] - c;
        if (g > 0) s.insert(g);
    }
    int p = 0;
    while (!s.empty()){
        ++p; ++ans;
        auto it = prev(s.end());
        int v = *it;
        s.erase(it);
        s.insert(v - 1);
        auto it2 = prev(s.end());
        if ((*it2) <= p) break;
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
 
    int t = 1;  cin >> t;
    while (t--)
    {
        solve();
    }
}