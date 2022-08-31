#include <bits/stdc++.h>
 
#define x first
#define y second
#define endl '\n'
 
#define int long long
#define ii pair<int, int>
 
using namespace std;
 
const int N = 2e5 + 5;
const int base = 311;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const long long INF = 1e18 + 7;
 
int a[N];
 
void solve(){
 string s;
 cin >> s;
 int cntn = 0, cnte = 0;
 for(char i : s){
  if (i == 'N') cntn++;
  else cnte++;
 }
 if (cntn == 1 && s.size() > 1) cout << "NO" << endl;
 else cout << "YES" << endl;
}
 
signed main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 //freopen("QN.inp","r",stdin);
 //freopen("QN.out","w",stdout);
 
 int t = 1; cin >> t;
 while (t--){
  solve();
 }
 
 return 0;
}