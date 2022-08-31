/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
#define int long long
#define ii pair<int, int>
#define x first
#define y second
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N];
ii b[N];
bool f[N];
 
bool cmp(ii a, ii b){
    return a.x > b.x || (a.x == b.x && (a.y > b.y));
}
 
void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i]; f[i] = false;
        b[i] = {a[i] - (n - i + 1), i};
        //cout << b[i].x << " " << b[i].y << endl;
    }
    sort(b + 1, b + n + 1, cmp);
    for(int i = 1; i <= k; ++i){
        f[b[i].y] = true;
    }
    int tmp = 0, ans = 0;
    for(int i = 1; i <= n; ++i){
        //cout << f[i] << " ";
        if (f[i]){
            ++tmp;
        } else {
            ans += a[i] + tmp;
        } 
    } //cout << endl;
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