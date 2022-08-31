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

int a[N], b[N];

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    for(int i = 1; i <= n; ++i){
        int p = (1LL << b[i]);
        int k = a[i - 1] / p + 1;
        a[i] = k * p;
        if (a[i] % (p << 1) == 0) a[i] += p;
    }
    cout << a[n];
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