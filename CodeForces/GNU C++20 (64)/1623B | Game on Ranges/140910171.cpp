/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define ii pair<int, int>
#define x first
#define y second
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
ii a[N];
vector <int> v[N];
 
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n + 1; ++i) v[i].clear();
    for(int i = 1; i <= n; ++i){
        cin >> a[i].x >> a[i].y;
        v[a[i].x].push_back(a[i].y);
    }
    for(int i = 1; i <= n; ++i) 
        sort(v[i].begin(), v[i].end());
    for(int i = 1; i <= n; ++i){
        while(!v[i].empty()){
            int r = v[i].back();
            v[i].pop_back();
            if (i == r){
                cout << i << " " << r << " " << i << endl;
                continue;
            }
            if (!v[i + 1].empty() && v[i + 1].back() == r){
                cout << i << " " << r << " " << i << endl;
            } else {
                cout << i << " " << r << " " << v[i].back() + 1 << endl;
            }
        }
    }
    cout << endl;
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
}