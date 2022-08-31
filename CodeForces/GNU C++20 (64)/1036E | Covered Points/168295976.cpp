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
 
const int N = 1000 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
const long double EPS = 1e-9;
 
set <pair<int, int>> s;
pair<int, int> a[N], b[N];
 
pair<long double, long double> get(pair<long double, long double> A, pair<long double, long double> B, pair<long double, long double> C, pair<long double, long double> D)
{
    // Line AB represented as a1x + b1y = c1
    long double a1 = B.second - A.second;
    long double b1 = A.first - B.first;
    long double c1 = a1*(A.first) + b1*(A.second);
 
    // Line CD represented as a2x + b2y = c2
    long double a2 = D.second - C.second;
    long double b2 = C.first - D.first;
    long double c2 = a2*(C.first)+ b2*(C.second);
 
    long double determinant = a1*b2 - a2*b1;
 
    if (determinant == 0)
    {
        // The lines are parallel. This is simplified
        // by returning a pair of FLT_MAX
        return make_pair(FLT_MAX, FLT_MAX);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return make_pair(x, y);
    }
}
 
bool ispint(pair<long double, long double> p){
    int x = p.first;
    int y = p.second;
    return (max(abs(p.first - x), abs(p.second - y)) <= EPS);
}
 
bool isin(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    //check if C in AB
    if (a.first > b.first) swap(a.first, b.first);
    if (a.second > b.second) swap(a.second, b.second);
    return (a.first <= c.first && c.first <= b.first) && (a.second <= c.second && c.second <= b.second);
}
 
set <pair<int, int>> u[N];
 
void solve()
{
    int n, ans = 0; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
        cin >> b[i].first >> b[i].second;
 
        ans += __gcd(abs(b[i].first - a[i].first), abs(b[i].second - a[i].second)) + 1;
    }
 
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            pair<long double, long double> p = get(a[i], b[i], a[j], b[j]);
 
            if (p.first == FLT_MAX) continue;
 
            pair<int, int> pint = p;
            if (ispint(p) && isin(a[i], b[i], p) && isin(a[j], b[j], p)){
                if (u[i].find(pint) == u[i].end()){
                    u[i].insert(pint);
                    --ans;
                }
                if (u[j].find(pint) == u[j].end()){
                    u[j].insert(pint);
                    --ans;
                }
                s.insert(pint);
            }
        }
    }
    ans += (int)s.size();
    cout << ans;
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