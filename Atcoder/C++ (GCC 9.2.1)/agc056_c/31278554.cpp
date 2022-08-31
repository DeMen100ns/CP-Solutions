/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

vector <pair<int, int>> a[N];
int d[N];
deque <int> q;

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int l, r;
        cin >> l >> r;
        a[l - 1].push_back({r, 0});
        a[r].push_back({l - 1, 0});
    }
    for(int i = 0; i < n; ++i){
        a[i].push_back({i + 1, 1});
        a[i + 1].push_back({i, 1});
        d[i] = N;
    } d[n] = N;
    d[0] = 0;
    q.push_back(0);
    while (!q.empty()){
        int u = q.front();
        q.pop_front();
        for(pair <int, int> i : a[u]){
            int v = i.first, w = i.second;
            if (d[u] + w < d[v]){
                d[v] = d[u] + w;
                if (w == 0){
                    q.push_front(v);
                } else {
                    q.push_back(v);
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        int p = d[i] - d[i - 1];
        if (p == 1) p = 0;
        else p = 1;
        cout << p;
    }
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