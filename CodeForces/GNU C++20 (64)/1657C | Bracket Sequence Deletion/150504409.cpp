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
 
const int N = 5e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
const int base = 311;
 
const int MOD = 1e9 + 7;
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod; }
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod; }
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x; }
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x; }
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1; } return ans; }
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod); }
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod); }
 
int pr[5], n;
array<int, 5> pw[N], hashs[N], hasht[N];
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int randint(int l, int r){
    return uniform_int_distribution <int> (l, r) (rng);
}
 
__int128 binpower(__int128 base, __int128 e, __int128 mod) {__int128 result = 1;base %= mod;while (e){if (e & 1)result = (__int128)result * base % mod;base = (__int128)base * base % mod;e >>= 1;    }return result;}
bool check_composite(__int128 n, __int128 a, __int128 d, int s) {__int128 x = binpower(a, d, n); if (x == 1 or x == n - 1)return false;for (int r = 1; r < s; r++) {x = (__int128)x * x % n;if (x == n - 1)return false;}return true;};
bool checkprime(__int128 n) {if (n < 2)return false;int r = 0;__int128 d = n - 1;while ((d & 1) == 0) {d >>= 1;r++;}for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {if (n == a)return true;if (check_composite(n, a, d, r))return false;}return true;}
 
array<int, 5> gethash(array<int, 5> hashs[], int l, int r){
    array<int, 5> res;
    --l;
    for(int j = 0; j < 5; ++j){
        res[j] = sum(hashs[r][j], -prod(hashs[l][j], pw[r - l][j], pr[j]), pr[j]);
    }
    return res;
}
 
bool palin(int l, int r){
    return (gethash(hashs, l, r) == gethash(hasht, n - r + 1, n - l + 1));
}
 
void setup(string s, string s2){
    int n = s.size() - 1;
    int k = randint(8e8, 1e9);
    for(int i = k, cnt = 0; cnt < 5; ++i){
        if (checkprime(i)){
            pr[cnt++] = i;
        }
    }
    pw[0] = {1, 1, 1, 1, 1};
    for(int j = 0; j < 5; ++j){
        for(int i = 1; i <= n; ++i){
            pw[i][j] = prod(pw[i - 1][j], base, pr[j]);
        }
    }
    for(int j = 0; j < 5; ++j){
        for(int i = 1; i <= n; ++i){
            int v;
            if (s[i] == '(') v = 1;
            else v = 2;
            hashs[i][j] = sum(prod(hashs[i - 1][j], base, pr[j]), v, pr[j]);
        }
    }
    for(int j = 0; j < 5; ++j){
        for(int i = 1; i <= n; ++i){
            int v;
            if (s2[i] == '(') v = 1;
            else v = 2;
            hasht[i][j] = sum(prod(hasht[i - 1][j], base, pr[j]), v, pr[j]);
        }
    }
}
 
void solve(){
 cin >> n;
    string s; cin >> s;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    s = " " + s; s2 = " " + s2;
    setup(s, s2);
    int cur = 0, l = 1, ans = 0, last = 0, mi = 0;
    for(int i = 1; i <= n; ++i){
     if (s[i] == '(') cur++;
     else cur--;
        mi = min(mi, cur);
     if (cur == 0 && mi >= 0){
      ++ans;
      last = i;
            l = i + 1;
            mi = 0;
     } else if (i > l && palin(l, i)){
            ++ans;
            last = i;
            l = i + 1;
            mi = 0;
            cur = 0;
        }
    }
    cout << ans << " " << n - last << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    //freopen("codeforces.inp","r",stdin);
    //freopen("codeforces.out","w",stdout);
    
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}