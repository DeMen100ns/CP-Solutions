/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
/*
Sauce : https://codeforces.com/problemset/problem/990/G
 
Tag : Inc - Exc, tree, dp
 
Solution : Bao hàm loại trừ cơ bản.
 
Note : -
 
Complexity : O(N * B) (thấp hơn trên thực tế ?)
*/
 
#include <bits/stdc++.h>
 
//#define int long long
 
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
 
vector <int> a[N], v[N];
int u[N], c[N], sz[N];
long long dp[N];
bool f[N], curc[N];
 
int dfs(int u, int color, int par = 0){
 f[u] = true;
 int ans = 1;
 for(int i : a[u]){
  if (i == par || !curc[i]) continue;
  ans += dfs(i, color, u);
 }
 return ans;
}
 
long long calc(int color){
 long long ans = 0;
 if (v[color].empty()) return 0;
 for(int i : v[color]){
  curc[i] = true;
 }
 for(int i : v[color]){
  if (!f[i]){
   int num = dfs(i, color);
   ans += num * 1LL * (num + 1) / 2;
  }
 }
 //dbg(v[color]);
 //dbgm(color, ans);
 for(int i : v[color]) f[i] = curc[i] = false;
 return ans;
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
    for(int i = 1; i <= n; ++i){
     for(int j = 1; j * j <= c[i]; ++j){
      if (c[i] % j == 0){
       v[j].push_back(i);
       if (j * j == c[i]) break;
       v[c[i] / j].push_back(i);
      }
     }
    }
    for(int i = 1; i <= MAXA; ++i){
     dp[i] = calc(i);
    }
    /*for(int i = 1; i <= MAXA; ++i){
     if (dp[i]){
      cout << i << " " << dp[i] << endl;
     }
    }*/
    for(int i = MAXA; i; --i){
     for(int j = 2 * i; j <= MAXA; j += i){
      dp[i] -= dp[j];
     }
    }
    for(int i = 1; i <= MAXA; ++i){
     if (dp[i]){
      cout << i << " " << dp[i] << endl;
     }
    }
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