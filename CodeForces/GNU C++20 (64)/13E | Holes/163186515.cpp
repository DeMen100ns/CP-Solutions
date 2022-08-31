/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
 
const int N = 1e5 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], nxt[N], nxtb[N], cntjump[N];
int block[2 * N], L[N], R[N], n;
 
void calnxtb(int lu, int ru){
    for(int i = ru; i >= lu; --i){
        if (nxt[i] > R[block[i]]){
            nxtb[i] = nxt[i];
            cntjump[i] = 1;
            continue;
        }
        nxtb[i] = nxtb[nxt[i]];
        cntjump[i] = cntjump[nxt[i]] + 1;
    }
}
 
void upd(int u, int val){
    a[u] = val; nxt[u] = u + val;
 
    calnxtb(L[block[u]], R[block[u]]);
    if (block[u] == 1) return;
    calnxtb(L[block[u] - 1], R[block[u] - 1]);
}
 
pair<int, int> get(int u){
    int cnt = 0;
    while (u <= n){
        cnt += cntjump[u];
        if (nxtb[u] > n){
            while (nxt[u] <= n){
                u = nxt[u];
            }
            return {u, cnt};
        }
        u = nxtb[u];
    }
    return {0, 0};
}
 
void solve()
{
    int q; cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        block[i] = (i - 1) / B + 1;
        nxt[i] = i + a[i];
    }
    for(int i = 1; i <= B; ++i) L[i] = (i - 1) * B + 1, R[i] = min(n, i * B);
    for(int i = 1; i <= n; ++i){
        int u = i;
        while (block[u] == block[i]){
            u = nxt[u];
            nxtb[i] = u;
            ++cntjump[i];
        }
    }
    while (q--){
        int type, u, v;
        cin >> type >> u;
        if (!type){
            cin >> v;
            upd(u, v);
        } else {
            //dbg(nxt, 1, n);
            //dbg(nxtb, 1, n);
            pair<int, int> ans = get(u);
            cout << ans.first << " " << ans.second << endl;
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