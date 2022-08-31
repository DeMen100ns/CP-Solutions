/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define x first
#define y second
 
using namespace std;
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
map <int, int> cnt;
 
void solve(){
 cnt.clear();
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
     int x;
     cin >> x;
     cnt[x]++;
    }
    for(auto i : cnt){
     if (i.y > 0 && cnt[-i.x] > 0) continue;
     if (i.y > 1){
      cnt[-i.x]++;
      cnt[i.x]--;
     }
    }
    int ans = 0;
    for(auto i : cnt){
     if (i.y > 0) ++ans;
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
}