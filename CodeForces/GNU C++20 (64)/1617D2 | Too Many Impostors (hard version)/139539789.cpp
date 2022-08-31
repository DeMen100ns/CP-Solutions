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
 int p0, p1, ans3, ans1, ans2, p2, p3;
 for(int i = 1; i <= n; i += 3){
  cout << "? " << i << " " << i + 1 << " " << i + 2 << endl;
  cin >> block[i];
  block[i] = 1 - block[i];
  if (block[i] == 0) p0 = i;
  else p1 = i;
 }
 p2 = p0;
 p3 = p1;
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
 for(int i = 1; i <= n; i += 3){
  int v1 = -1, v2 = -1, v3 = -1, ct = 0;
  if (i == p0) v1 = 0, ct++;
  if (i + 1 == p0) v2 = 0, ct++;
  if (i + 2 == p0) v3 = 0, ct++;
  if (i == p1) v1 = 1, ct++;
  if (i + 1 == p1) v2 = 1, ct++;
  if (i + 2 == p1) v3 = 1, ct++;
  if (max({v1, v2, v3}) == -1){
   if (block[i] == 0){
    cout << "? " << i << " " << i + 1 << " " << p1 << endl;
    cin >> ans1; ans1 = 1 - ans1;
    cout << "? " << i + 1 << " " << i + 2 << " " << p1 << endl;
    cin >> ans2; ans2 = 1 - ans2;
    if (ans1 > 0 && ans2 == 0){
     pos.push_back(i);
    }
    else if (ans1 == 0 && ans2 > 0){
     pos.push_back(i + 2);
    }
    else if (ans1 > 0 && ans2 > 0){
     pos.push_back(i + 1);
    }
   } else {
    cout << "? " << i << " " << i + 1 << " " << p0 << endl;
    cin >> ans1; ans1 = 1 - ans1;
    cout << "? " << i + 1 << " " << i + 2 << " " << p0 << endl;
    cin >> ans2; ans2 = 1 - ans2;
    if (ans1 == 0 && ans2 > 0){
     pos.push_back(i + 1);
     pos.push_back(i + 2);
    }
    else if (ans1 > 0 && ans2 == 0){
     pos.push_back(i);
     pos.push_back(i + 1);
    }
    else if (ans1 == 0 && ans2 == 0){
     pos.push_back(i);
     pos.push_back(i + 2);
    } else {
     pos.push_back(i);
     pos.push_back(i + 1);
     pos.push_back(i + 2);
    }
   }
  }
  if (ct == 2){
   if (block[i] == 1){
    if (v1 == -1) pos.push_back(i);
    if (v2 == -1) pos.push_back(i + 1);
    if (v3 == -1) pos.push_back(i + 2);
   }
   continue;
  }
  if (v1 == 0){
   if (block[i] == 1){
    pos.push_back(i + 1);
    pos.push_back(i + 2);
   } else {
    cout << "? " << p0 << " " << p1 << " " << i + 1 << endl;
    cin >> ans1; ans1 = 1 - ans1;
    cout << "? " << p0 << " " << p1 << " " << i + 2 << endl;
    cin >> ans2; ans2 = 1 - ans2;
    if (ans1 == 1) pos.push_back(i + 1);
    if (ans2 == 1) pos.push_back(i + 2);
   }
   continue;
  }
  if (v2 == 0){
   if (block[i] == 1){
    pos.push_back(i);
    pos.push_back(i + 2);
   } else {
    cout << "? " << p0 << " " << p1 << " " << i << endl;
    cin >> ans1; ans1 = 1 - ans1;
    cout << "? " << p0 << " " << p1 << " " << i + 2 << endl;
    cin >> ans2; ans2 = 1 - ans2;
    if (ans1 == 1) pos.push_back(i);
    if (ans2 == 1) pos.push_back(i + 2);
   }
   continue;
  }
  if (v3 == 0){
   if (block[i] == 1){
    pos.push_back(i);
    pos.push_back(i + 1);
   } else {
    cout << "? " << p0 << " " << p1 << " " << i << endl;
    cin >> ans1; ans1 = 1 - ans1;
    cout << "? " << p0 << " " << p1 << " " << i + 1 << endl;
    cin >> ans2; ans2 = 1 - ans2;
    if (ans1 == 1) pos.push_back(i);
    if (ans2 == 1) pos.push_back(i + 1);
   }
   continue;
  }
  if (v1 == 1){
   if (block[i] == 0){
    //pos.push_back(i);
   } else {
    //pos.push_back(i);
    cout << "? " << p0 << " " << p1 << " " << i + 1 << endl;
    cin >> ans1; ans1 = 1 - ans1;
    cout << "? " << p0 << " " << p1 << " " << i + 2 << endl;
    cin >> ans2; ans2 = 1 - ans2;
    if (ans1 == 1) pos.push_back(i + 1);
    if (ans2 == 1) pos.push_back(i + 2);
   }
   continue;
  }
  if (v2 == 1){
   if (block[i] == 0){
    //pos.push_back(i + 1);
    //pos.push_back(i + 2);
   } else {
    //pos.push_back(i + 1);
    cout << "? " << p0 << " " << p1 << " " << i << endl;
    cin >> ans1; ans1 = 1 - ans1;
    cout << "? " << p0 << " " << p1 << " " << i + 2 << endl;
    cin >> ans2; ans2 = 1 - ans2;
    if (ans1 == 1) pos.push_back(i);
    if (ans2 == 1) pos.push_back(i + 2);
   }
   continue;
  }
  if (v3 == 1){
   if (block[i] == 0){
    //pos.push_back(i + 2);
    //pos.push_back(i + 1);
   } else {
    //pos.push_back(i + 2);
    cout << "? " << p0 << " " << p1 << " " << i << endl;
    cin >> ans1; ans1 = 1 - ans1;
    cout << "? " << p0 << " " << p1 << " " << i + 1 << endl;
    cin >> ans2; ans2 = 1 - ans2;
    if (ans1 == 1) pos.push_back(i);
    if (ans2 == 1) pos.push_back(i + 1);
   }
   continue;
  }
 }
 cout << "! " << pos.size() << " ";
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