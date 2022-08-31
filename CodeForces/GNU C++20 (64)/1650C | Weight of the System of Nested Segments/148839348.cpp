/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
using ii = pair<int, int>;
#define x first
#define y second
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
array <int, 3> a[N];
 
void solve(){
    vector <pair<int, int>> ans;
    int n, m, s = 0;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        cin >> a[i][1] >> a[i][0];
        a[i][2] = i;
    }
    sort(a + 1, a + m + 1);
    for(int i = 1; i <= 2 * n; ++i){
        ans.push_back({a[i][1], a[i][2]});
        s += a[i][0];
    }
    sort(ans.begin(), ans.end());
    cout << s << endl;
    for(int l = 0, r = ans.size() - 1; l <= r; ++l, --r){
        cout << ans[l].y << " " << ans[r].y << endl;
    }
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
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}