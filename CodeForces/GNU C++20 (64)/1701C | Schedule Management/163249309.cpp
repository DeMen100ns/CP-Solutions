/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int cnt[N], cnt2[N], tme[N];
set <pair<int, int>> s;
 
void solve()
{
    int n, m, p; cin >> n >> m;
    fill(cnt + 1, cnt + n + 1, 0);
    for(int i = 1; i <= m; ++i){
        int x; cin >> x;
        cnt[x]++;
    }
    int l = 0, r = 3 * m;
    while (l + 1 < r){
        int mid = (l + r) >> 1;
        int tme = 0, p = 0;
        for(int i = 1; i <= n; ++i){
            tme += max(0ll, mid - cnt[i]) / 2;
            p += max(0ll, cnt[i] - mid);
        }
        //cout << mid << " " << tme << " " << p << endl;
        if (tme >= p) r = mid;
        else l = mid;
    }
    cout << r << endl;
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