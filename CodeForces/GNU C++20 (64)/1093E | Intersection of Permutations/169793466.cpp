/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
 
Name: Intersection of Permutations
Sauce: https://codeforces.com/contest/1093/problem/E
Tag: SQRT
 
Note: 
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
 
#define int long long
 
const int N = 2e5 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 2e5;
const int B = 1000;
 
int a[N], b[N], v[N], p[N];
int block[N], L[N], R[N];
int fen[N / B + 5][N];
 
inline void upd(int fen[], int pos, int val){
    for(int i = pos; i <= MAXA; i += i & -i){
        fen[i] += val;
    }
}
 
inline int get(int fen[], int pos){
    int ans = 0;
    for(int i = pos; i; i -= i & -i) ans += fen[i];
    return ans;
}
 
inline get_range(int fen[], int l, int r){
    return get(fen, r) - get(fen, l - 1);
}
 
inline bool f(int a, int b, int c){
    return (a <= b && b <= c);
}
 
inline int get_ans(int la, int ra, int lb, int rb){
    int ans = 0;
    int bl = block[lb], br = block[rb];
 
    if (bl == br){
        for(int i = lb; i <= rb; ++i){
            ans += f(la, p[i], ra);
        }
        return ans;
    }
 
    for(int i = lb; i <= R[bl]; ++i){
        ans += f(la, p[i], ra);
    }
    for(int i = L[br]; i <= rb; ++i){
        ans += f(la, p[i], ra);
    }
    ++bl; --br;
    for(int i = bl; i <= br; ++i){
        ans += get_range(fen[i], la, ra);
    }
 
    return ans;
}
 
void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i], v[a[i]] = i;
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
        p[i] = v[b[i]];
        block[i] = (i - 1) / B + 1;
        upd(fen[block[i]], p[i], 1);
    }
 
    for(int i = 1; i <= block[n]; ++i){
        R[i] = i * B;
        L[i] = R[i] - B + 1;
        R[i] = min(R[i], n);
    }
 
    while (m--){
        int type, la, ra, lb, rb, x, y;
        cin >> type;
 
        if (type == 1){
            cin >> la >> ra >> lb >> rb;
 
            cout << get_ans(la, ra, lb, rb) << endl;
        } else {
            cin >> x >> y;
 
            int bx = block[x], by = block[y];
 
            upd(fen[bx], p[x], -1);
            upd(fen[by], p[y], -1);
 
            swap(p[x], p[y]);
 
            upd(fen[bx], p[x], 1);
            upd(fen[by], p[y], 1);
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1; //cin >> t;
    while (t--)
    {
        solve();
    }
}