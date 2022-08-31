/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 500 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
set <int> s;
 
int a[N][N];
 
void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n * k; ++i){
        s.insert(i);
    }
    for(int i = 1; i <= n; ++i){
        int c = *s.begin();
        for(int j = 1; j <= k; ++j){
            int cur = c + 2 * (j - 1);
            if (cur > n * k){
                cout << "NO" << endl;
                return;
            }
            a[i][j] = cur;
        }
        for(int j = 1; j <= k; ++j){
            s.erase(c + 2 * (j - 1));
        }
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            cout << a[i][j] << " ";
        } cout << endl;
    }
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