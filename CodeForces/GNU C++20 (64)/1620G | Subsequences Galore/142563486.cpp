/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
/*
Problem : Subsequences Galore - Codeforces Educational Codeforces Round 119
Sauce : https://codeforces.com/contest/1620/problem/G
Tag : DP SOS
 
Solution :
- F(mask) : Số xâu thỏa là subsequence của ít nhất 1 string có bit bật trong mask 
- G(mask) : Số xâu thỏa là subsequence của các string có bit bật trong mask và không phải subsequence của các string còn lại 
- H(mask) : Số xâu thỏa là subsequence của các string có bit bật trong mask 
 
H(mask) = prod(min(cnt[i][c] | i = 1 -> n AND mask >> 1 & 1 = true) + 1 | c = 'a' -> 'z')
H(mask) -> G(mask) : Inv SOS
G(mask) -> F(mask) : SOS
 
Note : -
 
Complexity : O(2 ^ n * n * 26) (maybe)
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
 
const int MOD = 998244353;
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod; }
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod; }
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x; }
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x; }
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1; } return ans; }
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod); }
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y), mod); }
 
const int N = (1 << 23) + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int cnt[24][27], mi[27];
int f[N], notf[N], g[N], h[N];
 
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
     string s; cin >> s;
     for(char c : s){
      cnt[i][c - 'a']++;
     }
    }
    int m = (1 << n) - 1;
    for(int mask = 0; mask <= m; ++mask) h[mask] = 1;
    for(int mask = 1; mask <= m; ++mask){
     for(int j = 0; j < 26; ++j) mi[j] = MAXA;
     for(int i = 0; i < n; ++i){
      if (mask & (1 << i)){
       for(int j = 0; j < 26; ++j){
        mi[j] = min(mi[j], cnt[i][j]);
       }
      }
     }
     for(int j = 0; j < 26; ++j) mul(h[mask], mi[j] + 1);
    } 
 for(int mask = 0; mask <= m; ++mask) g[mask] = h[mask]; 
    for(int i = 0; i < n; ++i){
     for(int mask = 0; mask <= m; ++mask){
      if ((mask & (1 << i)) == 0){
       add(g[mask], -g[mask ^ (1 << i)]);
      }
     }
    }
    int s = 0;
    for(int mask = 0; mask <= m; ++mask){
     notf[mask] = g[mask];
     add(s, notf[mask]);
    }
    for(int i = 0; i < n; ++i){
     for(int mask = 0; mask <= m; ++mask){
      if (mask & (1 << i)){
       add(notf[mask], notf[mask ^ (1 << i)]);
      }
     }
    }
    for(int mask = 0; mask <= m; ++mask){
     f[mask] = sum(s, -notf[m ^ mask]);
    }
    int ans = 0;
    for(int mask = 1; mask <= m; ++mask){
     int cnt = 0, sum = 0;
     for(int i = 0; i < n; ++i){
      if (mask & (1 << i)){
       ++cnt;
       sum += i + 1;
      }
     }
     ans ^= (cnt * sum * f[mask]);
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