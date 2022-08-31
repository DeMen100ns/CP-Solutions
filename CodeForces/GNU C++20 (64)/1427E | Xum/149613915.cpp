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
 
const int N = 1e6 + 5;
const long long INF = (1LL << 40);
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
vector <int> basis;
vector <array<int, 3>> ans;
int a[N];
 
void ins(int a){
 for(auto i : basis){
        ans.push_back({a, 1, i});
        a = min(a, a ^ i);
 }
    if (a) basis.push_back(a);
}
 
bool check(int a = 1){
    for(auto i : basis){
        a = min(a, a ^ i);
    }
    return (a == 0);
}
 
int msb(int i){
    i |= (i >> 1);
    i |= (i >> 2);
    i |= (i >> 4);
    i |= (i >> 8);
    i |= (i >> 16);
    i |= (i >> 32);
    return (i + 1) >> 1;
}
 
int randint(int l, int r){
    return uniform_int_distribution <int> (l, r) (rng);
}
 
void solve(){
    int n, cnt;
    cin >> n;
    a[cnt = 1] = n;
    ins(n);
    while (cnt < N - 5){
        ++cnt;
        int l, r;
        while (1){
            l = randint(1, cnt - 1);
            r = randint(1, cnt - 1);
            if (a[l] + a[r] <= INF && !check(a[l] + a[r])) break;
        }
        a[cnt] = a[l] + a[r];
        ans.push_back({a[l], 0, a[r]});
        ins(a[cnt]);
        if (check()) break;
       // cout << cnt << endl;
    }    
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i[0];
        if (i[1] == 0) cout << " + ";
        else cout << " ^ ";
        cout << i[2] << endl; 
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