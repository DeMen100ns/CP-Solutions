//demen luoi code :(
 
#include <bits/stdc++.h>
 
using namespace std;
 
signed main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 
 int n, k;
 cin >> n >> k;
 map<vector<pair<int, int>>, int> c;
 long long ans = 0;
 for(int i = 0; i < n; ++i) {
  int a;
  cin >> a;
  map<int, int> cnt;
  for(int j = 2; j * j <= a; ++j) {
   while(a % j == 0) {
    cnt[j]++;
    a /= j;
   }
  }
  if (a != 1) 
   cnt[a] = 1;
  vector<pair<int, int>> z;
  for(auto i: cnt) {
   i.second = i.second % k;
   if (i.second != 0)
    z.emplace_back(i.first, i.second);
  }
  ans += c[z];
  for(auto &i: z)
   i.second = k - i.second;
  c[z]++;
 }
 cout << ans << '\n';
}