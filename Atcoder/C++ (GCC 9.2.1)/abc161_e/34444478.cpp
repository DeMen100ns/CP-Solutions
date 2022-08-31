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

const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

set <int> s;
char C[N];
int L[N], R[N];

void solve()
{
    int n, k, c; cin >> n >> k >> c;
    for(int i = 1; i <= n; ++i){
        cin >> C[i];
    }
    int p = -MAXA, cnt = 0;
    for(int i = 1; i <= n; ++i){
        if (C[i] == 'o'){
            if (i >= p + c + 1){
                ++cnt;
                p = i;
                L[cnt] = p;
            }
        }
    }
    if (cnt != k) return;

    p = MAXA;
    for(int i = n; i; --i){
        if (C[i] == 'o' && i <= p - c - 1){
            p = i;
            R[cnt] = p;
            --cnt;
        }
    }
    for(int i = 1; i <= k; ++i){
        int cnt = 0, pos = 0;
        for(int j = L[i]; j <= R[i]; ++j){
            if (C[j] == 'o'){
                ++cnt; pos = j;
            }
        }
        if (cnt == 1) cout << pos << endl;
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