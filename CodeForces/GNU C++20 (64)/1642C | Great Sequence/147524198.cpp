/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 3e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
map <int, int> cnt;
set <int> s;
 
void solve(){
    cnt.clear();
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        cnt[x]++;
    }
    for(auto i : cnt){
        if (cnt.find(i.first * k) == cnt.end()) continue;
        int mi = min(i.second, cnt[i.first * k]);
        cnt[i.first] -= mi;
        cnt[i.first * k] -= mi;
    }
    int ans = 0;
    for(auto i : cnt){
        ans += i.second;
    }
    cout << ans << endl;
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