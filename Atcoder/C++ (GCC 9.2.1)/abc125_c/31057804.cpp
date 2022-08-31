/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int a[N], pref[N], suf[N];

void solve()
{
    int n; cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1, j = n; i <= n; ++i, --j){
		pref[i] = __gcd(pref[i - 1], a[i]);
		suf[j] = __gcd(suf[j + 1], a[j]);
	}
	int ma = 0;
	for(int i = 1; i <= n; ++i){
		ma = max(ma, __gcd(pref[i - 1], suf[i + 1]));
	}
	cout << ma;
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