/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>

#define int unsigned long long
  
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

void solve()
{
    int n; cin >> n;
	int pw = 1, l = 1, r = 9, ans = 11;
	for(int i = 1; i <= 9; ++i){
		pw *= 10;
		for(int p = 2; p <= 17; ++p){
			int L = l - 1, R = r + 1;
			while (L + 1 < R){
				int mid = (L + R) >> 1;
				int tmp = mid;
				for(int j = 1; j < p; ++j){
					if (n / tmp < pw){
						tmp = n + 1;
						break;
					}
					tmp = tmp * pw + mid;
				}
				if (tmp <= n) L = mid, ans = max(ans, tmp);
				else R = mid;
			}
		}
		l = pw, r = pw * 10 - 1;
	}
	cout << ans << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1; cin >> t;
    while (t--)
    {
        solve();
    }
}