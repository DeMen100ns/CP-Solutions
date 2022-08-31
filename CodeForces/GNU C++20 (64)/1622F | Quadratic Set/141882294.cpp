/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 1e6 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int d[N + 5], rd[N + 5], a[N + 5], gt[N + 5], prodgt[N + 5];
vector <int> pr;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, sumxor = 0;
 
void sieve(){
 for(int i = 1; i <= N - 5; ++i){
  d[i] = i;
 }
 for(int i = 2; i * i <= N; ++i){
  if (d[i] != i) continue;
  for(int j = 2; i * j <= N; ++j){
   d[i * j] = i;
  }
 }
}
 
int randint(int l, int r){
 return uniform_int_distribution <int> (l, r) (rng);
}
 
set <int> s;
map <int, int> m;
 
bool case1(){
 for(int i = 1; i <= n; ++i){
  if (gt[i] == sumxor){
   s.erase(i);
   return true;
  }
 }
 return false;
}
 
bool case2(){
 for(int i = 1; i <= n; ++i){
  if (m[gt[i] ^ sumxor]){
   s.erase(i);
   s.erase(m[gt[i] ^ sumxor]);
   return true;
  }
 }
 return false;
}
 
void case3(){
 s.erase(2);
 s.erase((n - 1) / 2);
 s.erase(n);
}
 
void solve(){
 cin >> n;
 sieve();
 for(int i = 1; i <= n; ++i){
  rd[i] = randint(1, INF);
 }
 for(int i = 1; i <= n; ++i){
  int cur = i;
  while (cur > 1){
   a[i] ^= rd[d[cur]];
   cur /= d[cur];
  } 
  gt[i] = gt[i - 1] ^ a[i];
  sumxor ^= gt[i];
  s.insert(i);
  m[gt[i]] = i;
 }
 if (sumxor == 0){
  cout << s.size() << endl;
  for(int i : s) cout << i << " ";
  return;
 }
 if (case1()){
  cout << s.size() << endl;
  for(int i : s) cout << i << " ";
  return;
 }
 if (case2()){
  cout << s.size() << endl;
  for(int i : s) cout << i << " ";
  return;
 }
 case3();
 cout << s.size() << endl;
 for(int i : s) cout << i << " ";
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
}