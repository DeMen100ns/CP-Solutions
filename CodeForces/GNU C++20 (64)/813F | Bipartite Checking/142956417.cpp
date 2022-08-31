/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
/*
Problem : Bipartite Checking - Codeforces
Sauce : https://codeforces.com/contest/813/problem/F
 
Tag : graph, dsu, rollback
 
Solution :
 
Note :
 
Complexity :
*/
 
#include <bits/stdc++.h>
 
#define x first
#define y second
 
using namespace std;
using ii = pair<int, int>;
 
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); }
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int u[N], v[N], c[N], p[N], sz[N], val[N];
map <ii, int> st;
vector <ii> seg[4 * N];
stack <array<int, 4>> s;
int n;
set <ii> setedge;
bool wrong = false;
 
int root(int u){
    if (u == p[u]) return u;
    else return root(p[u]);
}
 
int getval(int u){
    if (u == p[u]) return 0;
    else return getval(p[u]) ^ val[u];
}
 
void Union(int ru, int rv, int u, int v){
    if (sz[ru] < sz[rv]) {swap(ru, rv); swap(u, v);}
    s.push({ru, rv, sz[ru], sz[rv]});
    if (getval(u) == getval(v)) val[rv] = 1;
    else val[rv] = 0;
    p[rv] = ru;
    sz[ru] += sz[rv];
}
 
void rollback(){
    if (s.empty()) return;
    array <int, 4> state = s.top();
    s.pop();
    int u = state[0], v = state[1];
    p[u] = u; p[v] = v;
    sz[u] = state[2];
    sz[v] = state[3];
}
 
void upd(int id, int l, int r, int u, int v, ii edge){
    if (l > v || r < u) return;
    if (l >= u && r <= v){
        seg[id].push_back(edge);
        return;
    }
    int mid = (l + r) >> 1;
    upd(id << 1, l, mid, u, v, edge);
    upd(id << 1 | 1, mid + 1, r, u, v, edge);
}
 
void dfs(int id, int l, int r){
    int ct = 0; bool change = wrong;
    for(auto i : seg[id]){
        if (wrong) break;
        int u = i.x, v = i.y, ru = root(i.x), rv = root(i.y);
        setedge.insert({u, v});
        if (ru == rv){
            if (getval(u) == getval(v)){
                wrong = true;
            }
        }
        else {Union(ru, rv, u, v); ++ct;}
    }
    change = change != wrong;
    if (l == r){
        if (!wrong) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else {
        int mid = (l + r) >> 1;
        dfs(id << 1, l, mid);
        dfs(id << 1 | 1, mid + 1, r);
    }
    if (change) wrong = false;
    for(auto i : seg[id]){
        int u = i.x, v = i.y;
        if (ct){
            rollback();
            --ct;
        }
        setedge.erase({u, v});
    }
}
 
void solve(){
 int q;
    cin >> n >> q;
    for(int i = 1; i <= q; ++i){
     cin >> u[i] >> v[i];
        if (u[i] > v[i]) swap(u[i], v[i]);
        if (st[{u[i], v[i]}] == 0){
            st[{u[i], v[i]}] = i;
        } else {
            upd(1, 1, q, st[{u[i], v[i]}], i - 1, {u[i], v[i]});
            st[{u[i], v[i]}] = 0;
        }
    }
    for(auto i : st){
        if (i.y){
            upd(1, 1, q, i.y, q, i.x);
        }
    }
    for(int i = 1; i <= n; ++i){
        sz[i] = 1; p[i] = i;
    }
    dfs(1, 1, q);
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