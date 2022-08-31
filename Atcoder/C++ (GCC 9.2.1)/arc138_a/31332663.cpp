/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

vector <pair<int, int>> v;
int a[N];

bool cmp(pair<int, int> a, pair<int, int> b){
    return (a.first > b.first) || (a.first == b.first && a.second < b.second);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = n;
    int mi1 = MAXA, ma2 = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if (i <= k) mi1 = min(mi1, a[i]);
        else ma2 = max(ma2, a[i]);
        v.push_back({a[i], i});
    }
    if (mi1 >= ma2){
        cout << -1; return;
    }
    sort(v.begin(), v.end(), cmp);
    int mi = n + 1;
    for(auto i : v){
        int v = i.first, p = i.second;
        if (p > k){
            mi = min(mi, p);
        } else {
            if (mi != n + 1){
                ans = min(ans, mi - p);
            }
        }
    }
    cout << ans;
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