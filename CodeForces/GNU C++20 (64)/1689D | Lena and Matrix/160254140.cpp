/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e3 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
char c[N][N];
int p[4][N][N];
 
void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 0; i <= n + 1; ++i){
        for(int j = 0; j <= m + 1; ++j){
            for(int t = 0; t < 4; ++t) p[t][i][j] = -MAXA; 
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> c[i][j];
            if (c[i][j] == 'B'){
                p[0][i][j] = -i - j;
                p[1][i][j] = -i + j;
                p[2][i][j] = i - j;
                p[3][i][j] = i + j;
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            p[0][i][j] = max({p[0][i][j], p[0][i - 1][j], p[0][i][j - 1]});
            p[1][i][m - j + 1] = max({p[1][i][m - j + 1], p[1][i][m - j + 2], p[1][i - 1][m - j + 1]});
            p[2][n - i + 1][j] = max({p[2][n - i + 1][j], p[2][n - i + 2][j], p[2][n - i + 1][j - 1]});
            p[3][n - i + 1][m - j + 1] = max({p[3][n - i + 1][m - j + 1], p[3][n - i + 2][m - j + 1], p[3][n - i + 1][m - j + 2]});
        }
    }
    int ans = n + m + n + m + 2; 
    pair<int, int> pos;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int g = max({i + j + p[0][i][j], i - j + p[1][i][j], -i + j + p[2][i][j], -i - j + p[3][i][j]});
            if (g < ans){
                ans = g;
                pos = {i, j};
            }
            //cout << g << " ";
        } //cout << endl;
    }
    cout << pos.first << " "  << pos.second << endl;
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