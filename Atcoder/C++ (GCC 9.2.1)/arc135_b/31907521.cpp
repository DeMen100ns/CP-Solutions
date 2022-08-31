/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 3e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int a[N], b[N], c[N];

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if (i > 1) b[i - 1] = a[i] - a[i - 1];
    }
    for(int i = 1; i <= 3; ++i){
        int x = i, sum = 0, mi = 0;
        while (x < n){
            sum += b[x];
            mi = min(mi, sum);
            x += 3;
        }
        c[i] = -mi;
    }
    if (c[1] + c[2] + c[3] > a[1]){
        cout << "No"; return;
    }
    c[1] += (a[1] - c[1] - c[2] - c[3]);
    for(int i = 4; i <= n + 2; ++i){
        c[i] = a[i - 2] - c[i - 1] - c[i - 2];
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= n + 2; ++i){
        cout << c[i] << " ";
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