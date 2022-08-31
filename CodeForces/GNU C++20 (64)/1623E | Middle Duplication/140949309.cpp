/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define ii pair<int, int>
//#define int long long
#define x first
#define y second
 
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
 
int l[N], r[N], pv[N];
bool dou[N], ok[N];
string s;
deque <int> pos[N];
int n, k;
 
void dfs(int u){
    if (u == 0) return;
    dfs(l[u]);
    dfs(r[u]);
    if (pos[l[u]].size() > pos[r[u]].size()){
        swap(pos[u], pos[l[u]]);
        pos[u].push_back(u);
        for(int i : pos[r[u]]){
            pos[u].push_back(i);
        }
        pos[r[u]].clear();
    } else {
        swap(pos[u], pos[r[u]]);
        pos[u].push_front(u);
        reverse(pos[l[u]].begin(), pos[l[u]].end());
        for(int i : pos[l[u]]){
            pos[u].push_front(i);
        }
        pos[l[u]].clear();
    }
}
 
bool dfs_opt(int u, int h){
    bool f = false;
    if (ok[pv[u]] && k >= h){
        k -= h;
        dou[u] = true;
        if (l[u]) dfs_opt(l[u], 1);
        if (r[u]) dfs_opt(r[u], 1);
        return true;
    } else {
        if (l[u]) f |= dfs_opt(l[u], h + 1);
        if (f) dou[u] = true;
        if (dou[u] && r[u]) dfs_opt(r[u], 1);
        return dou[u];
    }
}
 
void solve(){
    cin >> n >> k;
    cin >> s; s = " " + s;
    for(int i = 1; i <= n; ++i){
        cin >> l[i] >> r[i];
    }
    dfs(1);
    string x = " ";
    for (int i : pos[1]) x += s[i];
    s = x;
    for(int i = 0; i < n; ++i) pv[pos[1][i]] = i + 1;
    int l = 1;
    for(int i = 1; i < n; ++i){
        if (s[i] != s[i + 1]){
            if (s[i] < s[i + 1]){
                for(int j = l; j <= i; ++j) ok[j] = true;
            }
            l = i + 1;
        }
    }
   // dbg(s);
   // dbg(pos[1]);
   // dbg(ok, 1, n);
   // dbg(pv, 1, n);
    dfs_opt(1, 1);
    for(int i = 1; i <= n; ++i){
        cout << s[i];
        if (dou[pos[1][i - 1]]) cout << s[i];
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