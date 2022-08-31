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
 
const int MOD = 1e9 + 7;
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod; }
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod; }
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x; }
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x; }
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1; } return ans; }
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod); }
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y), mod); }
 
const int N = (1 << 17) + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int cnt[N], a[N], ab[N], c[N], d[N], e[N], de[N], f[N], ans[N];
int fhat[18][N], ghat[18][N], h[18][N];
int n, m;
 
int fpow(int n, long long k, int p = (int) 1e9 + 7) {
    int r = 1;
    for (; k; k >>= 1) {
        if (k & 1) r = (long long) r * n % p;
        n = (long long) n * n % p;
    }
    return r;
}
 
void XORFFT(int a[], int n, int p, int invert) {
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i; k++) {
                int u = a[j + k], v = a[i + j + k];
                a[j + k] = u + v;
                if (a[j + k] >= p) a[j + k] -= p;
                a[i + j + k] = u - v;
                if (a[i + j + k] < 0) a[i + j + k] += p;
            }
        }
    }
    if (invert) {
        long long inv = fpow(n, p - 2, p);
        for (int i = 0; i < n; i++) a[i] = a[i] * inv % p;
    }
}
 
void subsetconvo(){
 for(int i = 0; i <= m; ++i){
  int cntbit = __builtin_popcount(i);
  fhat[cntbit][i] = ghat[cntbit][i] = c[i];
 }
 for(int i = 0; i <= 17; ++i){
  for(int j = 0; j <= 17; ++j){
   for(int mask = 0; mask <= m; ++mask){
    if ((mask & (1 << j)) == 0) continue;
    add(fhat[i][mask], fhat[i][mask ^ (1 << j)]);
    ghat[i][mask] = fhat[i][mask];
   }
  }
 }
 for(int i = 0; i <= 17; ++i){
  for(int j = 0; j <= i; ++j){
   for(int mask = 0; mask <= m; ++mask)
    add(h[i][mask], prod(fhat[j][mask], ghat[i - j][mask]));
  }
 }
 for(int i = 0; i <= 17; ++i){
  for(int j = 0; j <= 17; ++j){
   for(int mask = 0; mask <= m; ++mask){
    if ((mask & (1 << j)) == 0) continue;
    add(h[i][mask], -h[i][mask ^ (1 << j)]);
   }
  }
 }
 for(int i = 0; i <= m; ++i)
  ab[i] = h[__builtin_popcount(i)][i];
}
 
void andconvo(){
 for(int mask = 0; mask <= m; ++mask){
  mul(ab[mask], f[mask]);
  mul(c[mask], f[mask]);
  mul(de[mask], f[mask]);
 }
 //dbg(ab, 0, 10);
 //dbg(c, 0, 10);
 //dbg(de, 0, 10);
 for(int i = 0; i < 17; ++i){
  for(int mask = 0; mask <= m; ++mask){
   if ((mask & (1 << i))) continue;
   add(ab[mask], ab[mask ^ (1 << i)]);
   add(c[mask], c[mask ^ (1 << i)]);
   add(de[mask], de[mask ^ (1 << i)]);
  }
 }
 for(int mask = 0; mask <= m; ++mask){
  ans[mask] = prod(ab[mask], prod(c[mask], de[mask]));
 }
 //dbg(ans, 0, 10);
 for(int i = 0; i < 17; ++i){
  for(int mask = 0; mask <= m; ++mask){
   if ((mask & (1 << i))) continue;
   add(ans[mask], -ans[mask ^ (1 << i)]);
  }
 }
 //dbg(ans, 0, 10);
 int res = 0;
 for(int i = 1; i <= m; i <<= 1){
  add(res, ans[i]);
  //dbg(i, ans[i]);
 }
 cout << res;
}
 
void solve(){
 m = (1 << 17) - 1;
    cin >> n;
    f[1] = 1;
    for(int i = 2; i <= m; ++i){
     f[i] = sum(f[i - 1], f[i - 2]);
    }
    for(int i = 1; i <= n; ++i){
     int k; cin >> k;
     d[k] = e[k] = ++c[k];
    }
    subsetconvo();
    XORFFT(d, m + 1, MOD, 0);
    XORFFT(e, m + 1, MOD, 0);
    for(int i = 0; i <= m; ++i) de[i] = prod(d[i], e[i]);
    XORFFT(de, m + 1, MOD, 1);
 //dbg(de,0,5);
 andconvo();
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