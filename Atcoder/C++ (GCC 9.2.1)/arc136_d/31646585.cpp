/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e6 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e6;
const int B = sqrt(N) + 5;

int a[N], dp[N], pw[10];

int get(int n, int k){
	return (n / pw[k]) % 10;
}

bool check(int n){
	while(n){
		int d = n % 10;
		if (d >= 5) return false;
		n /= 10;
	} return true;
}

void solve()
{
    int n; cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		dp[a[i]]++;
	}
	pw[0] = 1;
	for(int i = 1; i < 6; ++i) pw[i] = pw[i - 1] * 10;
	for(int i = 0; i < 6; ++i){
		for(int m = MAXA - 1; m >= 0; --m){
			int d = get(m, i);
			for(int newd = d + 1, newm = m + pw[i]; newd <= 9; ++newd, newm += pw[i]){
				dp[newm] += dp[m];
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		ans += dp[(MAXA - 1) - a[i]];
	}
	for(int i = 1; i <= n; ++i){
		ans -= check(a[i]);
	}
	cout << ans / 2;
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