/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = (1 << 20) + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int a[N], dp[N];

void solve()
{
    int n, m, mask = (1 << 20) - 1; cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		dp[mask ^ (n - i)] = a[i];
	}
	for(int b = 0; b < 20; ++b){
		for(int i = 0; i <= mask; ++i){
			if (i >> b & 1) dp[i ^ (1 << b)] ^= dp[i];
		}
	}
	for(int i = 1; i <= m; ++i) cout << dp[i - 1] << " ";
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