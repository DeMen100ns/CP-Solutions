/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], b[N];
 
void solve()
{
    vector <pair<int, int>> ans;
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            if (a[i] > a[j]){
                ans.push_back({i, j});
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            if (b[i] > b[j]){
                if (a[i] == a[j]){
                    ans.push_back({i, j});
                    swap(b[i], b[j]);
                } else {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i.first << " " << i.second << endl;
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