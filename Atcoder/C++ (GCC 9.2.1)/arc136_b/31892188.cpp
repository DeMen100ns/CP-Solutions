/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], b[N];
multiset <int> s, s2;
 
void solve()
{
    int n; cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i], s.insert(a[i]);
	for(int i = 1; i <= n; ++i) cin >> b[i], s2.insert(b[i]);
	if (s != s2){
		cout << "No"; return;
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = i + 1; j <= n; ++j){
			if (a[i] == a[j]){
				cout << "Yes"; return;
			}
			cnt += a[i] > a[j];
			cnt -= b[i] > b[j];
		}
	}
	if (cnt % 2 == 0){
		cout << "Yes";
	} else {
		cout << "No";
	}
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