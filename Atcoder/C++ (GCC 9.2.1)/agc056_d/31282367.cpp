/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/

/*
Note : 
- S = a[1] + a[2] + ... + a[n]
- Alice : s
- Bob : S - s
-> Alice - Bob : s - S + s = 2s - S
- L <= s <= R
-> 2L - S <= 2s - S <= 2R - S
- X = S - (L + R)
-> |X + 2s - S| <= R - L
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e3 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int a[N];
vector <int> v1;

void solve()
{
    int n, l, r, S = 0, ans = 1e18; cin >> n >> l >> r;
    for(int i = 1; i <= n; ++i){
        cin >> a[i]; S += a[i];
        v1.push_back(a[i]);
    }
    sort(v1.begin(), v1.end());
    int x = S - (l + r);
    for(int i = 1; i <= n; ++i){
        int res = 0;
        vector <int> v2 = {a[i], a[i] + x};
        if (v2[0] > v2[1]) swap(v2[0], v2[1]);
        vector <int> v3;
        merge(v1.begin(), v1.end(), v2.begin(), v2.end(),back_inserter(v3));
        for(int i = 0; i < v3.size(); i += 2){
            res += v3[i + 1] - v3[i];
        }
        ans = min(ans, res);
    }
//    cout << ans << endl;
    if (ans <= r - l){
        cout << "Alice";
    } else cout << "Bob";
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