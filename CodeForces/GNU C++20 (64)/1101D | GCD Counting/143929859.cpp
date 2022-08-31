/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
/*
Sauce : https://codeforces.com/problemset/problem/1101/D
 
Tag : SQRT, tree, dp
 
Solution : B = sqrt(2e5);
Xét 2 th :
- gcd <= B : Gán đỉnh có màu 1 nếu chia hết và màu 0 nếu không chia hết cho gcd. Tìm đường đi dài nhất có màu 1. 
Đpt : O(n) với mỗi gcd.
- gcd > B : Gán đỉnh có màu là ước nguyên tố lớn nhất, tìm đường đi dài nhất có cùng màu.
Đpt : O(n)
 
Note : Chỉ duyệt các số nguyên tố để giảm số lần chạy
 
Complexity : O(N * B) (thấp hơn trên thực tế ?)
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 2e5;
const int B = sqrt(N) + 5;
 
int c[N], curc[N], u[N];
vector <int> a[N];
vector <int> v[N];
int f[N], ct, h[N];
pair <int, int> ma[N];
 
void dfs(int u, int color, int par = 0){
 //dbgm(u, color, par);
 f[u] = ct;
 for(int i : a[u]){
  if (i == par || curc[i] != color) continue;
  h[i] = h[u] + 1;
  dfs(i, color, u);
 }
}
 
int calc(int color){
 if (v[color].empty()) return 0;
 //dbg(v, 1, 4);
 //dbg(curc, 1, 3);
 ct = 0;
 for(int u : v[color]){
  if (!f[u]){
   ++ct;
   dfs(u, color);
  }
 }
 //dbg(h, 1, 3);
 for(int u : v[color]){
  ma[f[u]] = max(ma[f[u]], {h[u], u});
  h[u] = 0;
 }
 for(int i = 1; i <= ct; ++i){
  dfs(ma[i].second, color);
  ma[i] = {-1, -1};
 }
 int ans = -1;
 for(int u : v[color]){
  ans = max(ans, h[u]);
 }
 for(int u : v[color]) f[u] = h[u] = 0;
 return ans + 1;
}
 
void solve(){
 int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
     cin >> c[i];
    }
    for(int i = 1; i < n; ++i){
     int u, v;
     cin >> u >> v;
     a[u].push_back(v);
     a[v].push_back(u);
    }
    for(int i = 1; i <= MAXA; ++i) u[i] = i;
    for(int i = 2; i <= MAXA; ++i){
     if (u[i] != i) continue;
     for(int j = 2 * i; j <= MAXA; j += i){
      u[j] = i;
     }
    }
    for(int i = 2; i <= B; ++i){
     if (u[i] != i) continue;
     for(int j = 1; j <= n; ++j){
      if (c[j] % i == 0){
       v[1].push_back(j);
       curc[j] = 1;
      } else curc[j] = 0;
     }
     ans = max(ans, calc(1));
     v[1].clear();
    }
    for(int i = 1; i <= n; ++i){
     curc[i] = u[c[i]];
     v[u[c[i]]].push_back(i);
    }
    for(int i = 2; i <= MAXA; ++i){
     ans = max(ans, calc(i));
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