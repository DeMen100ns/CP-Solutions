/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
 
Name:
Sauce: 
Tag: 
Sol: 
Note: 
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[2 * N], b[2 * N];
 
void solve()
{
    int n, k, cnt = 0; cin >> n >> k;
    bool f = false, ff = true;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        ff &= (a[i] == 0);
        if (ff) cnt = i;
        f |= (a[i] >= k);
    }
    if (f){
        cout << 0; return;
    }
    n -= cnt;
    for(int i = 1; i <= n; ++i){
        a[i] = a[i + cnt];
    }
 
    if (n <= 3){
        if (n == 2){
            int tmp = k - a[2];
            tmp = (tmp + (a[1] - 1)) / a[1];
 
            cout << tmp;
        } else {
            //(1) (0, 1) (0, 0, 1)
            //(1) (1, 1) (1, 1, 1)
            //(1) (2, 1) (3, 2, 1)
            //(1) (3, 1) (6, 3, 1)
            int l = 0, r = 2e9 + 10;
            while (l + 1 < r){
                int mid = (l + r) >> 1;
                __int128_t sum = (__int128_t)(mid * (mid + 1) / 2) * a[1] + mid * a[2] + a[3];
 
                //dbgm(mid, sum);
 
                if (sum >= k) r = mid;
                else l = mid;
            }
            cout << r;
        }
        return;
    }
 
    for(int t = 1; t <= 1'000'000'000; ++t){
        bool f = false;
        for(int i = 1; i <= n; ++i){
            a[i] += a[i - 1];
            f |= (a[i] >= k);
        }
        if (f){
            cout << t; return;
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
 
    int t = 1; // cin >> t;
    while (t--)
    {
        solve();
    }
}