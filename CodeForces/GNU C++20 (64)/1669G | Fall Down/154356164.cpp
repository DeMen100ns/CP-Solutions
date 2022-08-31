/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
char c[55][55];
 
void solve()
{
    memset(c, 0, sizeof c);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> c[i][j];
        }
    }
    for(int i = n; i; --i){
        for(int j = 1; j <= m; ++j){
            if (c[i][j] == '*'){
                int p = i;
                while (p < n && c[p + 1][j] == '.'){
                    swap(c[p][j], c[p + 1][j]);
                    ++p;
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cout << c[i][j];
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
 
    int t = 1; cin >> t;
    while (t--)
    {
        solve();
    }
}