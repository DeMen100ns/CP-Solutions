/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc

Name: Construct Highway
Sauce: https://atcoder.jp/contests/abc239/tasks/abc239_f
Tag: Implement, DSU, Greedy
Sol: De vai
Note: 
*/

#include <bits/stdc++.h>

using namespace std;

template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);

const int N = 2e5 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int d[N], p[N];
vector <int> a[N];
vector <pair<int, int>> ans;

auto cmp = [](const int& x, const int& y){return a[x].size() > a[y].size();};

int root(int u){
    if (p[u] == u) return u;
    else return p[u] = root(p[u]);
}

void Union(int u, int v){
    u = root(u); v = root(v);
    if (u == v){
        cout << -1;
        exit(0);
    }
    p[v] = u;
}

void solve()
{
    int n, m, sum = 0; cin >> n >> m;
    multiset <int, bool(*)(const int&,const int&)> s(cmp);

    for(int i = 1; i <= n; ++i){
        cin >> d[i]; sum += d[i]; p[i] = i;
    }
    if (sum != (n - 1) * 2){
        cout << -1;
        return;
    }
    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        Union(u, v);
        d[u]--; d[v]--;
    }
    for(int i = 1; i <= n; ++i){
        if (d[i] < 0){
            cout << -1;
            return;
        }
        for(int j = 1; j <= d[i]; ++j){
            a[root(i)].push_back(i);
        }
    }
    for(int i = 1; i <= n; ++i){
        if (p[i] == i){
            s.insert(i);
        }
    }
    for(int i = 1; i <= n - m - 1; ++i){
        auto it = s.begin();
        auto it2 = next(s.begin());

        int u = *it, v = *it2;

        if (a[v].empty()){
            cout << -1;
            return;
        }
        ans.push_back({a[u].back(), a[v].back()});
        a[u].pop_back(); a[v].pop_back();

        for(int i : a[v]) a[u].push_back(i);

        s.erase(it2);
    }
    for(pair<int, int> i : ans) cout << i.first << " " << i.second << endl;
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