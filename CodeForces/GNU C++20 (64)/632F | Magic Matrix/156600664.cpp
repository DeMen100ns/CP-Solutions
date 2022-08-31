/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2500 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N][N];
bitset <N> bs[N];
vector <array<int, 3>> v;
vector <pair<int, int>> tmp;
 
void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
            if (i == j && a[i][j]){
                cout << "NOT MAGIC";
                return;
            }
            if (i > j && a[i][j] != a[j][i]){
                cout << "NOT MAGIC";
                return;
            }
            v.push_back({a[i][j], i, j});
        }
    }
    sort(v.begin(), v.end());
    int last = v[0][0];
    for(array<int, 3> s : v){
        if (s[0] != last){
            last = s[0];
            for(pair<int, int> i : tmp){
                bs[i.first].set(i.second);
            }
            tmp.clear();
        }
        if ((bs[s[1]] & bs[s[2]]).any()){
            cout << "NOT MAGIC";
            return;
        }
        tmp.push_back({s[1], s[2]});
    }
    cout << "MAGIC";
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