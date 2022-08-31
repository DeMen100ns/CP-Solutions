/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
/*
Day start : 09/06/2022
To - day  : 14/06/2022
Counting : 0012
*/
 
#include <bits/stdc++.h>
 
#define int long long
#define ii pair<int, int>
#define x first
#define y second
 
using namespace std;
 
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
 
const int MOD = 1e9 + 7;
void add(int &a, int b, int mod = MOD){ a += b; while (a < 0) a += mod; while (a >= mod) a -= mod; }
int sum(int a, int b, int mod = MOD){ return add(a, b, mod), a; }
void mul(int &a, int b, int mod = MOD){ a = (a * 1LL * b) % mod; }
int prod(int a, int b, int mod = MOD){ return mul(a, b, mod), a; }
int bpow(int a, int b, int mod = MOD){ int ans = 1; while (b){ if (b & 1){ mul(ans, a, mod); } mul(a, a, mod); b >>= 1; } return ans; }
int Inv(int a, int mod = MOD){ return bpow(a, mod - 2, mod); }
int Div(int a, int b, int mod = MOD) { return prod(a, Inv(b, mod), mod); }
 
const int N = 6e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 3e5;
const int B = sqrt(N) + 5;
 
int p[N], deg[N], sizx[N], sizy[N], ans = 0;
stack <array<int, 8>> st;
map<ii, int> m;
vector <ii> edge[2 * N];
 
int root(int u){
    if (u == p[u]) return u;
    else return root(p[u]);
}
 
int need(int id){
    if (sizx[id] < 2 || sizy[id] < 2) return 0;
    else return sizx[id] * sizy[id] - deg[id] / 2;
}
 
bool Union(int u, int v){
    if ((u = root(u)) == (v = root(v))) return false;
    if (sizx[u] + sizy[u] < sizx[v] + sizy[v]) swap(u, v);
 
    ans -= need(u); ans -= need(v);
 
    st.push({u, v, sizx[u], sizx[v], sizy[u], sizy[v], deg[u], deg[v]});
 
    p[v] = u;
    sizx[u] += sizx[v];
    sizy[u] += sizy[v];
    deg[u] += deg[v];
 
    ans += need(u);
 
    return true;
}
 
void rollback(){
    array <int, 8> state = st.top();
    st.pop();
    int u = state[0], v = state[1];
 
    ans -= need(u);
 
    p[u] = u; p[v] = v;
    sizx[u] = state[2]; sizx[v] = state[3];
    sizy[u] = state[4]; sizy[v] = state[5];
    deg[u] = state[6]; deg[v] = state[7];
 
    ans += need(u); ans += need(v);
}
 
void dfs(int id, int l, int r){
    set <ii> s; int mid = (l + r) >> 1;
 
    for(ii i : edge[id]){
        ++ans;
        deg[root(i.x)]++; deg[root(i.y)]++;
        if (Union(i.x, i.y)){
            s.insert(i);
        } else --ans;
    }
    reverse(edge[id].begin(), edge[id].end());
 
    if (l == r){
        cout << ans << " ";
 
        goto skip;
    }
 
    dfs(id << 1, l, mid);
    dfs(id << 1 | 1, mid + 1, r);
 
    skip:
    for(ii i : edge[id]){
        --ans;
        if (s.find(i) != s.end()){
            rollback();
        } else ++ans;
        deg[root(i.x)]--; deg[root(i.y)]--;
    }
}
 
void upd(int id, int l, int r, int u, int v, ii val){
    if (l > v || r < u) return;
    if (l >= u && r <= v){
        edge[id].push_back(val);
        return;
    }
    int mid = (l + r) >> 1;
    upd(id << 1, l, mid, u, v, val);
    upd(id << 1 | 1, mid + 1, r, u, v, val);
}
 
void solve()
{
    for(int i = 1; i <= 2 * MAXA; ++i){
        p[i] = i;
        if (i <= MAXA) sizx[i] = 1;
        else sizy[i] = 1;
    }
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        int x, y; cin >> x >> y;
        y += MAXA;
        if (m.find({x, y}) != m.end()){
            upd(1, 1, n, m[{x, y}], i - 1, {x, y});
            m.erase(m.find({x, y}));
        } else {
            m[{x, y}] = i;
        }
        if (i == n){
            for(auto p : m){
                upd(1, 1, n, p.y, n, p.x);
            }
        }
    }
    dfs(1, 1, n);
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 //freopen("checklist.in", "r", stdin);
 //freopen("checklist.out", "w", stdout);
 
    int t = 1; //cin >> t;
    while (t--)
    {
        solve();
    }
}