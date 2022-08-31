/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
const int MOD = 1e9 + 7;
 
vector <int> basis; 
vector <pair<int, int>> v[N];
int a[N], ans[N];
 
void ins(int a){
 for(int i : basis){
  a = min(a, a ^ i);
 }
    if (a) basis.push_back(a);
}
 
bool check(int a){
    for(int i : basis){
        a = min(a, a ^ i);
    }
    return (a == 0);
}
 
void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= q; ++i){
        int l, x; cin >> l >> x;
        v[l].push_back({x, i});
    }
    int p = 1;
    for(int i = 1; i <= n; ++i){
        if (check(a[i])) p = (p << 1) % MOD;
        else ins(a[i]);
        for(pair<int, int> j : v[i]){
            if (!check(j.first)){
                ans[j.second] = 0;
            } else {
                ans[j.second] = p;
            }
        }
    }
    for(int i = 1; i <= q; ++i) cout << ans[i] << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    //freopen("codeforces.inp","r",stdin);
    //freopen("codeforces.out","w",stdout);
    
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}