/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
vector <int> x[N];
vector <int> y[N];
 
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int c;
            cin >> c;
            x[c].push_back(i);
            y[c].push_back(j);
        }
    }
    int ans = 0;
    for(int c = 1; c <= 1e5; ++c){
        sort(x[c].begin(), x[c].end());
        sort(y[c].begin(), y[c].end());
        int sum = 0, tme = x[c].size();
        for(int i : x[c]){
            sum += i;
        }
        for(int i : x[c]){
            --tme;
            sum -= i;
            ans += (sum - tme * i);
        }
        sum = 0, tme = y[c].size();
        for(int i : y[c]){
            sum += i;
        }
        for(int i : y[c]){
            --tme;
            sum -= i;
            ans += (sum - tme * i);
        }
    }
    cout << ans;
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
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}