/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
 
Name: 
Sauce: 
Tag: 
Sol: 
Note: 
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], b[N];
 
void solve()
{
    int n, ans = 0; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = 0;
 
    int p = n - 1;
    while(a[p] <= a[p + 1]){
        if (p == 0){
            cout << 0 << endl;
            return;
        }
        --p;
    }
    for(int i = 1; i <= p; ++i) b[a[i]] = 1;
 
    int p2 = n, cnt = 0;
    while(!b[a[p2]] && p2) --p2;
    
    for(int i = 1; i <= p2; ++i) b[a[i]] = 1;
    for(int i = 1; i <= n; ++i){
        cnt += b[i];
    }
    cout << cnt << endl;
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