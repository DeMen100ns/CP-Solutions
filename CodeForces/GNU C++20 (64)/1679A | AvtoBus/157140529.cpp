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
 
void solve()
{
    int n; cin >> n;
 if (n & 1 || n < 4){
  cout << -1 << endl;
  return;
 }
 cout << n / 6 + (n % 6 > 0) << " " << n / 4 << endl;
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