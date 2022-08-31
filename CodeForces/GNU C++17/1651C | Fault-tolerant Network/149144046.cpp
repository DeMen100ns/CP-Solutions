/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 1e6 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
using ii = pair<int, int>;
#define x first
#define y second
 
int dp[N][20], a[N], b[N];
vector <ii> s;
 
void solve(){
    s.clear();
 int n; cin >> n;
 for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i){
     int v = abs(a[1] - b[i]);
     int b = 1;
     if (i == 1) b |= 4;
     if (i == n) b |= 8;
     s.push_back({v, b});
    }
    for(int i = 1; i <= n; ++i){
        int v = abs(a[n] - b[i]);
        int b = 2;
        if (i == 1) b |= 4;
        if (i == n) b |= 8;
        s.push_back({v, b});
    }
    for(int i = 1; i <= n; ++i){
     int v = abs(b[1] - a[i]);
     int b = 4;
     if (i == 1) b |= 1;
     if (i == n) b |= 2;
     s.push_back({v, b});
    }
    for(int i = 1; i <= n; ++i){
     int v = abs(b[n] - a[i]);
     int b = 8;
     if (i == 1) b |= 1;
     if (i == n) b |= 2;
     s.push_back({v, b});
    }
    int len = s.size();
    for(int i = 0; i <= len; ++i){
     for(int j = 0; j < 16; ++j){
      dp[i][j] = INF;
     }
    }
    dp[0][0] = 0;
    for(int i = 0; i < len; ++i){
     for(int j = 0; j < 16; ++j){
      int v = s[i].x;
      int b = s[i].y;
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      dp[i + 1][j | b] = min(dp[i + 1][j | b], dp[i][j] + v);
     }
    }
    cout << dp[len][15] << endl;
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