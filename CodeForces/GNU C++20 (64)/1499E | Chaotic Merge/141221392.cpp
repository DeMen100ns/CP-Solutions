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
 
const int MOD = 998244353;
 
inline void add(int &x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
}
inline void mul(int &x, int y) { x = (x * 1LL * y) % MOD; }
 
inline int prod(int x, int y) { return mul(x, y), x; }
inline int sum(int x, int y) { return add(x, y), x; }
 
inline int bpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) mul(ans, x);
        mul(x, x);
        y >>= 1;
    }
    return ans;
}
 
inline int Div(int x, int y) { return prod(x, bpow(y, MOD - 2)); }
 
const int N = 1e3 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
string s, t;
int dp[N][N][2];
 
void solve(){
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s; t = " " + t;
    for(int i = 1; i <= n; ++i){
        dp[i][0][0] = 1;
     if (s[i] != s[i - 1]) add(dp[i][0][0], dp[i - 1][0][0]);
    }
    for(int j = 1; j <= m; ++j){
        dp[0][j][1] = 1;
     if (t[j] != t[j - 1]) add(dp[0][j][1], dp[0][j - 1][1]);
    }
    int ans = 0;
    for(int r1 = 1; r1 <= n; ++r1){
     for(int r2 = 1; r2 <= m; ++r2){
      if (s[r1] != s[r1 - 1]) add(dp[r1][r2][0], dp[r1 - 1][r2][0]);
      if (t[r2] != t[r2 - 1]) add(dp[r1][r2][1], dp[r1][r2 - 1][1]);
      if (s[r1] != t[r2]) {
       if (r1 > 1) add(dp[r1][r2][0], dp[r1 - 1][r2][1]);
       if (r2 > 1) add(dp[r1][r2][1], dp[r1][r2 - 1][0]);
                add(dp[r1][r2][0], dp[0][r2][1]);
                add(dp[r1][r2][1], dp[r1][0][0]);
      }
            add(ans, dp[r1][r2][0]);
            add(ans, dp[r1][r2][1]);
     }
    }
    //dp[n][m] = f(e, n, e, m) voi moi e ?
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