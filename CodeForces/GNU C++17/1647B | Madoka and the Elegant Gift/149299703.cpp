/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e3 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
 
using ii = pair<int, int>;
#define x first
#define y second
 
char c[N][N];
bool f[N][N];
int n, m;
 
bool valid(int i, int j){
    return (min(i, j) >= 1 && i <= n && j <= m);
}
 
bool bfs(int i, int j){
    queue <ii> q;
    q.push({i, j}); f[i][j] = true;
    int cnt = 0;
    ii mi = {i, j}, ma = {i, j};
    while (!q.empty()){
        ii u = q.front(); 
        q.pop(); ++cnt;
        mi.x = min(mi.x, u.x);
        mi.y = min(mi.y, u.y);
        ma.x = max(ma.x, u.x);
        ma.y = max(ma.y, u.y);
        for(int k = 0; k < 4; ++k){
            int i = u.x + dx[k], j = u.y + dy[k];
            if (valid(i, j) && !f[i][j] && c[i][j] == '1'){
                q.push({i, j});
                f[i][j] = true;
            }
        }
    }
    return (cnt == (ma.x - mi.x + 1) * (ma.y - mi.y + 1));
}
 
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
     for(int j = 1; j <= m; ++j){
      cin >> c[i][j];
            f[i][j] = false;
     }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if (c[i][j] == '1' && !f[i][j]){
                bool f = bfs(i, j);
                if (!f){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    //freopen("codeforces.inp","r",stdin);
    //freopen("codeforces.out","w",stdout);
    
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}