/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
 
Name: Graph Reconstruction
Sauce: https://codeforces.com/contest/329/problem/C
Tag: Constructive, Greedy
 
Note: 
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
set<pair<int, int>> s;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int randint(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}
 
void solve()
{
    int n, m; cin >> n >> m;
    
    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
 
        s.insert({u, v});
        s.insert({v, u});
    }
 
    vector <int> v(n);
    iota(v.begin(), v.end(), 1);
 
    for(int run = 1; run <= 100; ++run){
        shuffle(v.begin(), v.end(), rng);
 
        bool f = true;
        for(int i = 0; i < m; ++i){
            if (s.find({v[i], v[(i + 1) % n]}) != s.end()){
                f = false;
                break;
            }
        }
 
        if (!f) continue;
 
        for(int i = 0; i < m; ++i){
            cout << v[i] << " " << v[(i + 1) % n] << endl;
        } return;
    }
 
    cout << -1;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1; //cin >> t;
    while (t--)
    {
        solve();
    }
}