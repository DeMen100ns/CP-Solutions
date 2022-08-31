/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 4e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

multiset <int> s;
int a[N];

void solve()
{
    int n, sum = 0; cin >> n;
    for(int i = 1; i <= n * 2; ++i) cin >> a[i], sum += a[i];
    int l = n, r = n + 1;
    while (l){
        s.insert(a[l]);
        s.insert(a[r]);
        auto it = s.begin();
        sum -= *it;
        s.erase(it);
        --l; ++r;
    }
    cout << sum;
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