/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 1e3 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N][N];
int f[N][N], cnt[N][N];
 
int get(int i2, int j2, int i, int j){
    i2--; j2--;
    return a[i][j] ^ a[i2][j] ^ a[i][j2] ^ a[i2][j2];
}
 
void solve(){
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
            if (i % 2 == 0 && j % 2 == 1 && j < i) {
                ans ^= a[i][j];
                //cout << i << " " << j << endl;
            }
            if (i % 2 == 0 && j % 2 == 0 && j > n - i + 1) {
                ans ^= a[i][j];
                //cout << i << " " << j << endl;
            }
            a[i][j] ^= a[i - 1][j] ^ a[i][j - 1] ^ a[i - 1][j - 1];
        }
    }
    for(int i = 2; i <= n / 2; i += 2){
        ans ^= get(i, i, n - i + 1, n - i + 1);
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
 
/*
2 2 
2 2 
2 3 3 2 
3 4 4 3 
3 4 4 3 
2 3 3 2 
2 3 3 3 3 2 
3 4 4 4 4 3 
3 4 4 4 4 3 
3 4 4 4 4 3 
3 4 4 4 4 3 
2 3 3 3 3 2 
2 3 3 3 3 3 3 2 
3 4 4 4 4 4 4 3 
3 4 4 4 4 4 4 3 
3 4 4 4 4 4 4 3 
3 4 4 4 4 4 4 3 
3 4 4 4 4 4 4 3 
3 4 4 4 4 4 4 3 
2 3 3 3 3 3 3 2
*/