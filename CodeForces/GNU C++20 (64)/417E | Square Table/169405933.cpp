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
 
const int N = 100 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], b[N], c[N][N];
 
void cal(int a[], int n){
    if (n == 1){
        a[1] = 1;
        return;
    }
    if (n == 2){
        a[1] = 3; a[2] = 4;
        return;
    }
    if (n & 1){
        a[1] = 2;
        for(int i = 2; i < n; ++i) a[i] = 1;
        a[n] = (n + 1) / 2;
    } else {
        for(int i = 1; i < n; ++i) a[i] = 1;
        a[n] = (n - 2) / 2;
    }
}
 
void solve()
{
    int n, m; cin >> n >> m;
    cal(a, n);
    cal(b, m);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cout << a[i] * b[j] << " ";
        } cout << endl;
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