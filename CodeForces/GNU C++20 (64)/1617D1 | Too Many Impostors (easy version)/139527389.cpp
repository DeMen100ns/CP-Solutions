#include <bits/stdc++.h>
 
#define x first
#define y second
//#define endl '\n'
 
#define int long long
#define ii pair<int, int>
 
using namespace std;
 
const int N = 4e5 + 5;
const int base = 311;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int INF = 1e18 + 7;
 
vector <int> v, p[N];
int block[N];
 
void solve(){
 vector <int> pos;
 int n;
 cin >> n;
 int p0, p1, ans3, ans1, ans2;
 for(int i = 1; i <= n; i += 3){
  cout << "? " << i << " " << i + 1 << " " << i + 2 << endl;
  cin >> block[i];
  block[i] = 1 - block[i];
  if (block[i] == 0) p0 = i;
  else p1 = i;
 }
 cout << "? " << p0 << " " << p0 + 1 << " " << p1 << endl;
 cin >> ans1;  ans1 = 1 - ans1;
 cout << "? " << p0 << " " << p0 + 1 << " " << p1 + 1 << endl;
 cin >> ans2; ans2 = 1 - ans2;
 //cout << "? " << p0 << " " << p0 + 1 << " " << p1 + 2 << endl;
 //cin >> ans3; ans3 = 1 - ans3;
 if (max(ans1, ans2) == 0){
  //a[p0] = 0
  //a[p0 + 1] = 0
  cout << "? " << p1 << " " << p1 + 1 << " " << p0 << endl;
  cin >> ans1; ans1 = 1 - ans1;
  cout << "? " << p1 << " " << p1 + 2 << " " << p0 << endl;
  cin >> ans2; ans2 = 1 - ans2;
  //cout << "? " << p1 + 1 << " " << p1 + 2 << " " << p0 << endl;
  //cin >> ans3; ans3 = 1 - ans3;
  if (max(ans1, ans2) == 0) p1++;
 } else {
  //a[p1] + a[p2] = 1
  cout << "? " << p0 << " " << p0 + 2 << " " << p1 << endl;
  cin >> ans1; ans1 = 1 - ans1;
  cout << "? " << p0 << " " << p0 + 2 << " " << p1 + 1 << endl;
  cin >> ans2; ans2 = 1 - ans2;
  p1 = p0 + 1;
  if (max(ans1, ans2) > 0){
   swap(p0, p1);
  }
 }
 int cnt = 1;
 pos.push_back(p1);
 for(int i = 1; i <= n; ++i){
  if (i != p1 && i != p0){
   int a;
   cout << "? " << p0 << " " << p1 << " " << i << endl;
   cin >> a;
   a = 1 - a;
   cnt += a; 
   if (a) pos.push_back(i);
  }
 }
 cout << "! " << cnt << " ";
 for(int i : pos) cout << i << " ";
 cout << endl;
 //0 0 0 1 1 1
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