/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
 
const int MOD = 1e9 + 7;
inline void add(int &x, int y) { x += y; while (x >= MOD) x -= MOD; while (x < 0) x += MOD; }
inline void mul(int &x, int y) { x = (x * 1LL * y) % MOD; }
inline int prod(int x, int y) { return mul(x, y), x; }
inline int sum(int x, int y) { return add(x, y), x; }
inline int bpow(int x, int y) { int ans = 1; while (y) { if (y & 1) mul(ans, x); mul(x, x); y >>= 1; } return ans; }
inline int Inv(int x) { return bpow(x, MOD - 2); }
inline int Div(int x, int y) { return prod(x, Inv(y)); }
 
const int N = 100 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int l[N], r[N], c[N];
 
struct matrix{
 int m[16][16];
 
 void reset(){
  memset(m, 0, sizeof m);
 }
 
 void setup(int k){
  reset();
  for(int i = 0; i <= k; ++i){
   for(int add = -1; add <= 1; ++add){
    if (i + add >= 0 && i + add <= k){
     m[i][i + add] = 1;
    }
   }
  }
 }
};
 
matrix mulm(matrix a, matrix b){
 matrix res;
 for(int i = 0; i <= 15; ++i){
  for(int j = 0; j <= 15; ++j){
   res.m[i][j] = 0;
   for(int k = 0; k <= 15; ++k){
    add(res.m[i][j], prod(a.m[i][k], b.m[k][j]));
   }
  }
 }
 return res; 
}
 
matrix bpow(int n, matrix cur){
 if (n == 1) return cur;
 matrix res = bpow(n >> 1, cur);
 res = mulm(res, res);
 if (n & 1) res = mulm(res, cur);
 return res;
}
 
void solve(){
 int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
     cin >> l[i] >> r[i] >> c[i];
    }
    int cur = 0;
    matrix res;
    for(int i = 1; i <= n; ++i){
     if (r[i] > k) r[i] = k;
     matrix ans; ans.setup(c[i]);
     ans = bpow(r[i] - l[i], ans);
     if (i == 1) res = ans;
     else res = mulm(res, ans);
     if (r[i] == k) break;
     //dbg(i);
    }
    cout << res.m[0][0];
    //dbg(res.m, 0, 3, 0, 3);
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