/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
#define x first
#define y second
 
const int N = 5e3 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], fen[N], n;
vector <ii> vp, vn;
 
void upd(int pos, int v){
    for(int i = pos; i <= n; i += i & -i){
        fen[i] += v;
    }
}
 
int get(int pos){
    int ans = 0;
    for(int i = pos; i; i -= i & -i){
        ans += fen[i];
    } 
    return ans;
}
 
void solve()
{
    long long ans = 0; cin >> n;
    vp.clear(); vn.clear();
    for(int i = 1; i <= n; ++i){
        cin >> a[i]; fen[i] = 0;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            if (a[i] < a[j]) vp.push_back({i, j}); else vn.push_back({i, j});
        }
    }
    sort(vp.begin(), vp.end());
    sort(vn.begin(), vn.end());
    //[a, c], [b, d]
    int j = 0;
    for(ii p : vn){
        while(j < vp.size() && vp[j].x < p.x){
            upd(vp[j].y, 1);
            ++j;
        }
        ans += get(p.y - 1) - get(p.x);
        //[b + 1, d - 1], a < b
    }
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