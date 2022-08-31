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
    string s;
    cin >> s; s = " " + s;
    int n = s.size() - 1;
    int pos = -1;
    for(int i = 1; i < n; ++i){
        if (s[i] + s[i + 1] - '0' - '0' >= 10){
            pos = i;
        }
    }
    //cout << pos << endl;
    if (pos >= 0){
        for(int i = 1; i < pos; ++i){
            cout << s[i];
        }
        cout << (s[pos] + s[pos + 1] - '0' - '0');
        for(int i = pos + 2; i <= n; ++i) cout << s[i];
    } else {
        cout << s[1] + s[2] - '0' - '0';
        for(int i = 3; i <= n; ++i){
            cout << s[i];
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