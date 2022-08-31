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
    int l, r, ma = 0;
	cin >> l >> r;
	for(int i = l; i <= min(l + 300, r); ++i){
		for(int j = max(l, r - 300); j <= r; ++j){
			if (__gcd(i, j) == 1) ma = max(ma, abs(i - j));
		}
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