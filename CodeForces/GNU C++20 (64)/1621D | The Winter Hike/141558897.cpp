/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
#define x first
#define y second
 
#define ii pair<int, int>
 
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
 
const int N = 500 + 5;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N][N], d[N][N];
bool f[N][N];
int n;
priority_queue <pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
 
void dijkstra(){
    for(int i = 1; i <= n; ++i){
        //d[n + 1][i - 1 / i + 1]
        int pr = i - 1;
        int nt = i + 1;
        if (pr > 2 * n) pr = 1;
        if (nt > 2 * n) nt = 1;
        if (pr < 1) pr = 2 * n;
        if (nt < 1) nt = 2 * n;
        d[n + 1][pr] = min(d[n + 1][pr], a[n + 1][i] + a[n + 1][pr]);
        pq.push({d[n + 1][pr], {n + 1, pr}});
        d[n + 1][nt] = min(d[n + 1][nt], a[n + 1][i] + a[n + 1][nt]);
        pq.push({d[n + 1][nt], {n + 1, nt}});
        d[pr][n + 1] = min(d[pr][n + 1], a[i][n + 1] + a[pr][n + 1]);
        pq.push({d[pr][n + 1], {pr, n + 1}});
        d[nt][n + 1] = min(d[nt][n + 1], a[i][n + 1] + a[nt][n + 1]);
        pq.push({d[nt][n + 1], {nt, n + 1}});
        d[2 * n][pr] = min(d[2 * n][pr], a[2 * n][i] + a[2 * n][pr]);
        pq.push({d[2 * n][pr], {2 * n, pr}});
        d[2 * n][nt] = min(d[2 * n][nt], a[2 * n][i] + a[2 * n][nt]);
        pq.push({d[2 * n][nt], {2 * n, nt}});
        d[pr][2 * n] = min(d[pr][2 * n], a[i][2 * n] + a[pr][2 * n]);
        pq.push({d[pr][2 * n], {pr, 2 * n}});
        d[nt][2 * n] = min(d[nt][2 * n], a[i][2 * n] + a[nt][2 * n]);
        pq.push({d[nt][2 * n], {nt, 2 * n}});
    }
    while (!pq.empty()){
        ii u = pq.top().y;
        int du = pq.top().x;
        pq.pop();
        if (du != d[u.x][u.y]) continue;
        for(int k = 0; k < 4; ++k){
            int i = u.x + dx[k], j = u.y + dy[k];
            if (i > 2 * n) i = 1;
            if (i < 1) i = 2 * n;
            if (j > 2 * n) j = 1;
            if (j < 1) j = 2 * n;
            if (d[i][j] > d[u.x][u.y] + a[i][j]){
                d[i][j] = d[u.x][u.y] + a[i][j];
                pq.push({d[i][j], {i, j}});
            }
        }
    }
}
 
void solve(){
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= 2 * n; ++i)
        for(int j = 1; j <= 2 * n; ++j) {
            cin >> a[i][j];
            d[i][j] = 1e18;
            if (i > n && j > n){
                ans += a[i][j];
                //a[i][j] = 0;
            }
        }
    int mi = min({a[1][n + 1], a[1][2 * n]});
    mi = min({mi, a[n][n + 1], a[n][2 * n]});
    mi = min({mi, a[n + 1][1], a[n + 1][n]});
    mi = min({mi, a[2 * n][1], a[2 * n][n]});
    cout << ans + mi << endl;
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