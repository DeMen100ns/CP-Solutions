/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
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
 
int x[N], a[N], b[N], c[N], d[N], h[N];
 
vector <pair<ii, ii>> v[N];
vector <int> vp[N];
map <ii, int> dp;
 
void solve(){
 dp.clear();
 int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
     cin >> x[i];
    }
    for(int i = 1; i <= k; ++i){
     cin >> a[i] >> b[i] >> c[i] >> d[i] >> h[i];
     v[c[i]].push_back({{a[i], b[i]}, {d[i], h[i]}});
     vp[a[i]].push_back(b[i]);
     vp[c[i]].push_back(d[i]);
    }
    vp[1].push_back(1);
    vp[n].push_back(m);
    for(int i = 1; i <= n; ++i){
     sort(vp[i].begin(), vp[i].end());
     vp[i].resize(unique(vp[i].begin(), vp[i].end()) - vp[i].begin());
    }
   /* for(int i = 1; i <= n; ++i){
     dbg(v[i]);
     //dbg(vp[i]);
    }*/
    dp[{1, 1}] = 0;
    for(int i = 1; i <= n; ++i){
     for(auto j : v[i]){
      ii p = {i, j.y.x};
      if (dp.find(j.x) == dp.end()) continue;
      if (dp.find(p) == dp.end()){
       dp[p] = dp[j.x] - j.y.y; 
      } else {
       dp[p] = min(dp[p], dp[j.x] - j.y.y);
      }
     }
     for(int j = 0; j < (int)vp[i].size() - 1; ++j){
      ii prep = {i, vp[i][j]};
      ii nxtp = {i, vp[i][j + 1]};
      if (dp.find(prep) == dp.end()) continue;
      if (dp.find(nxtp) == dp.end()){
       dp[nxtp] = dp[prep] + (vp[i][j + 1] - vp[i][j]) * x[i];
      } else {
       dp[nxtp] = min(dp[nxtp], dp[prep] + (vp[i][j + 1] - vp[i][j]) * x[i]);
      }
     }
     for(int j = (int)vp[i].size() - 2; j >= 0; --j){
      ii prep = {i, vp[i][j + 1]};
      ii nxtp = {i, vp[i][j]};
      if (dp.find(prep) == dp.end()) continue;
      if (dp.find(nxtp) == dp.end()){
       dp[nxtp] = dp[prep] + (vp[i][j + 1] - vp[i][j]) * x[i];
      } else {
       dp[nxtp] = min(dp[nxtp], dp[prep] + (vp[i][j + 1] - vp[i][j]) * x[i]);
      }
     }
     //dbg(dp);
    }
    ii en = {n, m};
    if (dp.find(en) != dp.end()){
     cout << dp[{n, m}];
    } else {
     cout << "NO ESCAPE";
    } cout << endl;
    for(int i = 1; i <= n; ++i){
     vp[i].clear();
     v[i].clear();
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    //freopen("codeforces.inp","r",stdin);
    //freopen("codeforces.out","w",stdout);
    
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}