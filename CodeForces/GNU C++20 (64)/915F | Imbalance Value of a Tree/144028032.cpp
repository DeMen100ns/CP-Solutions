/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
/*
Sauce : https://codeforces.com/contest/915/problem/F
 
Tag : DSU
 
Solution : Đáp án là sigma(max(u -> v)) - sigma(min(u -> v))
Ta có thể tính sigma(max(c[i], i : u -> v)) đếm số đường đi qua các nút có giá trị c[i] = k, với mọi k
Tương tự với sigma(min(c[i], i : u -> v))
 
Note : -
 
Complexity : O(n * inv_ack(n))
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
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
vector <int> a[N], pos[N], cost;
int c[N], p[N], siz[N];
 
int root(int u){
 if (u == p[u]) return u;
 else return p[u] = root(p[u]);
}
 
int Union(int u, int v){
 u = root(u); v = root(v);
 if (u == v) return 0;
 if (siz[u] < siz[v]) swap(u, v);
 p[v] = u;
 int as = siz[u] * siz[v];
 siz[u] += siz[v];
 return as;
}
 
void solve(){
 int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
     cin >> c[i]; cost.push_back(c[i]);
     pos[c[i]].push_back(i);
     p[i] = i; siz[i] = 1;
    }
    for(int i = 1; i < n; ++i){
     int u, v;
     cin >> u >> v;
     a[u].push_back(v);
     a[v].push_back(u);
    }
    sort(cost.begin(), cost.end());
    cost.resize(unique(cost.begin(), cost.end()) - cost.begin());
    for(int co : cost){
     for(int u : pos[co]){
      for(int i : a[u]){
       if (c[i] > c[u]) continue;
       ans += Union(u, i) * co;
      }
     }
    }
    reverse(cost.begin(), cost.end());
    for(int i = 1; i <= n; ++i) p[i] = i, siz[i] = 1;
    for(int co : cost){
     for(int u : pos[co]){
      for(int i : a[u]){
       if (c[i] < c[u]) continue;
       ans -= Union(u, i) * co;
      }
     }
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