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
 
vector <int> basis;
int a[N];
 
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
    int n, sumall = 0, sumxor = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        sumxor ^= a[i];
        if (!check(sumxor)){
            ins(sumxor);
            sumxor = 0;
        }
        sumall ^= a[i];
    }
    if (sumall == 0) cout << -1;
    else cout << basis.size();
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