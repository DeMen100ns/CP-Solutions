/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
/*
Sauce : https://codeforces.com/problemset/problem/1491/E
 
Tag : Divide and Conquer, math
 
Solution : Nếu đáp án là yes thì mọi cách cắt cây thỏa đề bài đều ra được.
 
Note : Làm giống Centroid
 
Complexity : O(n * log(n)) (maybe?)
*/
 
#include <bits/stdc++.h>
 
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
 
int f[40], sub[N];
bool vis[N];
map <pair<int, int>, bool> cut;
vector <int> a[N];
 
int isfibo(int k){
 for(int i = 1; i < 40; ++i){
  if (k == f[i]) return i;
 }
 return 0;
}
 
pair<int, int> dfs_findcut(int u, int id, int par = 0){
    sub[u] = 1;
    for(int i : a[u]){
        if (i == par || cut[{u, i}]) continue;
        pair<int, int> ans = dfs_findcut(i, id, u);
        if (ans.first != -1) return ans;
        sub[u] += sub[i];
    }
    if (sub[u] == f[id - 1]) return {par, u};
    if (sub[u] == f[id - 2]) return {u, par};
    return {-1, -1};
}
 
bool fibocut(int u, int id){
    if (id <= 2) return true;
    pair <int, int> cutedge = dfs_findcut(u, id);
    cut[cutedge] = cut[{cutedge.second, cutedge.first}] = true;
    if (cutedge.first == -1) return false;
    return fibocut(cutedge.first, id - 2) & fibocut(cutedge.second, id - 1);
}
 
void solve(){
    int n;
    cin >> n;
    f[1] = 1;
    bool g = 0;
    for(int i = 2; i < 40; ++i){
     f[i] = f[i - 1] + f[i - 2];
    }
    int id = isfibo(n);
    if (!id){
        cout << "NO";
        return;
    }
    for(int i = 1; i < n; ++i){
     int u, v;
     cin >> u >> v;
     a[u].push_back(v);
     a[v].push_back(u);
    }
    g = fibocut(1, id);
    if (g) cout << "YES";
    else cout << "NO";
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