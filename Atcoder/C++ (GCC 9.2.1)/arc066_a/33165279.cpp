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

void solve()
{
    multiset <int> s;
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        s.insert(x);
    }
    for(int i = 1; i <= n; ++i){
        int l = i - 1;
        int r = n - l - 1;
        if (s.find(abs(r - l)) != s.end()) s.erase(s.find(abs(r - l)));
        else{
            cout << 0;
            return;
        }
    }
    n >>= 1;
    int ans = 1;
    while (n--){
        ans = (ans * 2) % (int)(1e9 + 7);
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