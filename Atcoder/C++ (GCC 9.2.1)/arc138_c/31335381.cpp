/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int a[N], p[N];
vector <pair<int, int>> v;

void solve()
{
    int n, s = 0; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    for(int i = 0; i < n; ++i){
        if (i < n / 2){
            p[v[i].second] = -1;
            s += v[i].first;
        } else p[v[i].second] = 1;
    }
    pair <int, int> mi = {p[1], 1};
    for(int i = 2; i <= n; ++i){
        p[i] += p[i - 1];
        mi = min(mi, {p[i], i});
    }
    cout << mi.second % n << " " << s;
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