/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
/*
Sauce : https://codeforces.com/contest/594/problem/D
 
Tag : Math, DS
 
Solution : 
phi(n) = n * (p1 - 1) / p1 * (p2 - 1) / p2 * ...
Update offline using Fenwick tree
 
Note : -
 
Complexity : O(n * logn * logai)
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
 
const int MOD = 1e9 + 7;
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod; }
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod; }
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x; }
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x; }
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1; } return ans; }
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod); }
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y), mod); }
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e6;
const int B = sqrt(N) + 5;
 
int n, a[N], ans[N], fen[N];
int u[MAXA + 5], suf[MAXA + 5];
vector <pair<int, int>> Q[N];
 
void upd(int pos, int val){
 for(int i = pos; i <= n; i += i & -i){
  mul(fen[i], val);
 }
}
 
int get(int pos){
 int as = 1;
 for(int i = pos; i; i -= i & -i){
  mul(as, fen[i]);
 }
 return as;
}
 
void solve(){
 cin >> n;
 for(int i = 1; i <= n; ++i) cin >> a[i], fen[i] = 1;
 int q;
 cin >> q;
 for(int i = 1; i <= q; ++i){
  int l, r;
  cin >> l >> r;
  Q[l].push_back({r, i});
 }
 for(int i = 1; i <= MAXA; ++i) u[i] = i;
 for(int i = 2; i <= MAXA; ++i){
  if (u[i] != i) continue;
  for(int j = 2 * i; j <= MAXA; j += i){
   u[j] = i;
  }
  suf[i] = n + 1;
 }
 for(int i = n; i; --i){
  upd(i, a[i]);
  while (a[i] > 1){
   int p = u[a[i]];
   while (a[i] % p == 0) a[i] /= p;
   upd(suf[p], prod(Inv(p - 1), p));
   suf[p] = i;
   upd(suf[p], prod(Inv(p), p - 1));
  }
  for(auto j : Q[i]){
   ans[j.second] = get(j.first);
  }
 } 
 for(int i = 1; i <= q; ++i){
  cout << ans[i] << endl;
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