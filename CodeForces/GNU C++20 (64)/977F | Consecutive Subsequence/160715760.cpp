#include "bits/stdc++.h"
using namespace std;
 
const int maxn = 2e5 + 6;
 
int n, arr[maxn], dp[maxn];
map<int, int> val;
 
int main(){
 ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 cin >> n;
 for(int i = 0; i < n; ++i) cin >> arr[i];
 
 int ans = 0, pos = 0;
 for(int i = 0; i < n; ++i){
  dp[i] = max(dp[i], val[arr[i] - 1] + 1);
  if(dp[i] > ans){
   ans = dp[i];
   pos = i;
  }
  val[arr[i]] = max(val[arr[i]], dp[i]);
 }
 
 cout << ans << '\n';
 
 stack<int> s;
 s.push(pos + 1);
 int cur = arr[pos];
 
 for(int i = pos; i >= 0; --i) if(arr[i] == cur - 1){
  cur = arr[i];
  s.push(i + 1);
 }
 
 while(!s.empty()) cout << s.top() << ' ', s.pop();
}