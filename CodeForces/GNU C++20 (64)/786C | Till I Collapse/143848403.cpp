/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
/*
Sauce : https://codeforces.com/contest/786/problem/C
 
Tag : DnC
 
Solution : 
- Nếu (f(l) == f(r)) : ans[l] = ... = ans[r] = f(l)
- Chứng minh được chỉ có tối đa 2 * sqrt(n) đáp án
 
Note : -
 
Complexity : O(n * sqrt(n) * log(n)) ()
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], ans[N], n;
bool f[N];
 
int F(int k){
 vector <int> v;
 int ct = 0, ctk = 1;
 for(int i = 1; i <= n; ++i){
  if (!f[a[i]]){
   f[a[i]] = true;
   ++ct;
   v.push_back(a[i]);
  }
  if (ct > k){
   for(int i : v) f[i] = false;
   v.clear();
   v.push_back(a[i]);
   ct = 1;
   ++ctk;
   f[a[i]] = true;
  }
 }
 for(int i : v) f[i] = false;
 v.clear();
 return ctk;
}
 
void dnc(int l, int r, int optl, int optr){
 if (optl == optr){
  for(int i = l; i <= r; ++i) ans[i] = optl;
  return;
 }
 int mid = (l + r) >> 1;
 dnc(l, mid, optl, F(mid));
 dnc(mid + 1, r, F(mid + 1), optr);
}
 
void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
     cin >> a[i];
    }
    dnc(1, n, F(1), F(n));
    for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
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