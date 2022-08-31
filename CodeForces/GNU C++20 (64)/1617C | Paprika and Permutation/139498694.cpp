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
int a[N];
int dp[N];
bool cnt[N];
 
void solve(){
 v.clear();
 int n;
 cin >> n;
 bool f = true;
 for(int i = 1; i <= n; ++i) cin >> a[i], cnt[i] = 0;
 sort(a + 1, a + n + 1);
 for(int i = 1; i <= n; ++i){
  if (a[i] <= n && cnt[a[i]] == 0){
   cnt[a[i]] = 1;
  } else v.push_back(a[i]);
 }
 int j = 0;
 for(int i = 1; i <= n; ++i){
  if (!cnt[i]){
   f &= (v[j] > 2 * i);
   ++j;
  }
 }
 if (!f) cout << -1;
 else cout << v.size();
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