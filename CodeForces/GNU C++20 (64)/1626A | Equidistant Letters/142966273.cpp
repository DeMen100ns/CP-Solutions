/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int cnt[200];
 
void solve(){
    memset(cnt, 0, sizeof cnt);
    string s;
    cin >> s;
    for(char i : s){
     cnt[i]++;
    }
    for(char c = 'a'; c <= 'z'; ++c){
     if (cnt[c] == 2) cout << c; 
    }
    for(char c = 'a'; c <= 'z'; ++c){
     if (cnt[c] == 1) cout << c; 
    }
    for(char c = 'a'; c <= 'z'; ++c){
     if (cnt[c] == 2) cout << c; 
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