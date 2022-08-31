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
 
int ans = 100, n;
 
int cntd(int u){
    int cnt = 0;
    while (u){
        u /= 10; cnt++;
    }
    return cnt;
}
 
bool check(int u){
    return cntd(u) == n;
}
 
void get(int x, int p){
    if (check(x)){
        ans = min(ans, p);
        return;
    }
 
    if (p >= ans || n - cntd(x) + p >= ans) return;
 
    ++p;
 
    bool vis[10];
    memset(vis, 0, sizeof vis);
 
    int cd = x;
    
    while (cd){
        int d = cd % 10;
        cd /= 10;
 
        if (d <= 1 || vis[d]) continue;
        get(x * d, p);
        
        vis[d] = true;
    }
}
 
void solve()
{
    int x; cin >> n >> x;
    get(x, 0); 
    if (ans == 100){
        cout << -1; return;
    }
    cout << ans;
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