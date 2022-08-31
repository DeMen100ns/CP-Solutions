/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int a[N];
vector <int> v;

void comp(int n){
    for(int i = 1; i <= n; ++i) v.push_back(a[i]);
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; ++i){
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }    
}

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    comp(n);
    int ans = (n + 1) / 2;
    for(int i = 1; i <= n; i += 2){
        ans -= (a[i] % 2);
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

    int t = 1; //cin >> t;
    while (t--)
    {
        solve();
    }
}