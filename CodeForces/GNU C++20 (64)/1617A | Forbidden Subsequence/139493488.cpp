#include <bits/stdc++.h>
 
#define x first
#define y second
#define endl '\n'
 
#define int long long
#define ii pair<int, int>
 
using namespace std;
 
const int N = 4e5 + 5;
const int base = 311;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int INF = 1e18 + 7;
 
vector <int> v, p[N];
ii a[N];
int dp[N];
 
void solve(){
 string s, t;
 cin >> s >> t;
 sort(s.begin(), s.end());
 int cnta = 0, cntb = 0, cntc = 0;
 for(char i : s){
  if (i == 'a') cnta++;
  if (i == 'b') cntb++;
  if (i == 'c') cntc++; 
 }
 if (t != "abc" || cnta == 0){
  cout << s << endl;
 } else {
  for(int i = 1; i <= cnta; ++i) cout << 'a';
  for(int i = 1; i <= cntc; ++i) cout << 'c';
  for(int i = 1; i <= cntb; ++i) cout << 'b';
  for(char i : s) if (i > 'c') cout << i;
  cout << endl;
 }
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