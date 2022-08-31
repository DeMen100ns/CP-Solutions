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
 
int a[N];
int pre[20][N];
 
void precal(){
    for(int j = 0; j <= 19; ++j){
        for(int i = 1; i <= 2e5 + 1; ++i){
            pre[j][i] = pre[j][i - 1] + ((i >> j) & 1);
        }
    }
}
 
void solve(){
 int l, r;
    cin >> l >> r;
    int ma = 0;
    for(int j = 0; j <= 19; ++j){
        ma = max(ma, pre[j][r] - pre[j][l - 1]);
    }
    cout << (r - l + 1) - ma << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    //freopen("codeforces.inp","r",stdin);
    //freopen("codeforces.out","w",stdout);
    precal();
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}