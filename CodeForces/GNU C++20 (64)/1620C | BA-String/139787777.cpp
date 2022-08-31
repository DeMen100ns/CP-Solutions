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
 
int a[N], ct[N];
 
void solve(){
 int n, k, x, cnt = 0;
 cin >> n >> k >> x;
 string s;
 cin >> s;
 --x;
 s = " " + s;
 for(int i = 1; i <= n; ++i){
  if (s[i] == '*' && s[i] != s[i - 1]) cnt++, ct[cnt] = 1;
  if (s[i] == '*' && s[i] == s[i - 1]) ct[cnt]++;
 }
 for(int i = cnt; i >= 1; --i){
  a[i] = x % (k * ct[i] + 1);
  x /= (k * ct[i] + 1);
 }
 //20 % 4 = 
 //reverse(a + 1, a + cnt + 1);
 int j = 1;
 for(int i = 1; i <= n; ++i){
  if (s[i] == 'a') cout << 'a';
  if (s[i] == '*' && s[i] != s[i - 1]){
   while (a[j]--){
    cout << 'b';
   }
   ++j;
  }
 }
 cout << endl;
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