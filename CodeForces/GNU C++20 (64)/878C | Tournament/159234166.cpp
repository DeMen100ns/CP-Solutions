/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
  
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int n, k;
 
struct node{
 int sz, mi[11], ma[11];
 
 bool operator < (const node a) const{
  for(int i = 1; i <= k; ++i){
   if (ma[i] > a.mi[i]) return false;
  }
  return true;
 }
 
 void merge(node a){
  sz += a.sz;
  for(int i = 1; i <= k; ++i){
   mi[i] = min(mi[i], a.mi[i]);
   ma[i] = max(ma[i], a.ma[i]);
  }
 }
};
 
set <node> s;
 
void solve()
{
    cin >> n >> k;
 while(n--){
  node a; a.sz = 1;
  for(int i = 1; i <= k; ++i){
   cin >> a.mi[i];
   a.ma[i] = a.mi[i]; 
  }
  auto it = s.upper_bound(a);
  if (it == s.begin()){
   s.insert(a); 
   cout << (*prev(s.end())).sz << endl;
   continue;
  }
 
  --it;
 
  while (it != s.begin() && !((*it) < a)){
   a.merge(*it);
   auto eit = it;
   --it;
   s.erase(eit);
  }
 
  if (!((*it) < a)){
   a.merge(*it);
   s.erase(it);
  }
 
  s.insert(a);
 
  cout << (*prev(s.end())).sz << endl;
 }
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1;// cin >> t;
    while (t--)
    {
        solve();
    }
}