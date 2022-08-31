/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
 
using ii = pair<int, int>;
#define x first
#define y second
 
const int N = (1 << 21) + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N];
ii dp[N];
 
void merge(ii &a, ii b){
 /*vector <int> v;
 v.push_back(a.x);
 v.push_back(a.y);
 v.push_back(b.x);
 v.push_back(b.y);
 sort(v.begin(), v.end());
 a = {v[3], v[2]};*/
 if (a.x > b.x){
  a = {a.x, max(a.y, b.x)};
 } else {
  a = {b.x, max(b.y, a.x)};
 }
}
 
void solve(){
 int n, m = (1 << 21) - 1;
 cin >> n;
 for(int i = 1; i <= n; ++i){
  cin >> a[i];
  merge(dp[a[i]], {i, 0});
 }
 for(int i = 0; i < 21; ++i){
  for(int mask = 0; mask <= m; ++mask){
   if (mask & (1 << i)){
    merge(dp[mask ^ (1 << i)], dp[mask]);
   }
  }
  //dbg(i);
 }
 int ans = 0;
 for(int i = 1; i <= n - 2; ++i){
  int cur = a[i], mask = 0;
  for(int j = 20; j >= 0; --j){
   if (a[i] & (1 << j)) continue;
   if (dp[mask ^ (1 << j)].y > i){
    //dbgm(i, j, cur, mask);
    mask ^= (1 << j);
    cur ^= (1 << j);
   }
  }
  //dbg(cur);
  ans = max(ans, cur);
 }
 cout << ans;
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