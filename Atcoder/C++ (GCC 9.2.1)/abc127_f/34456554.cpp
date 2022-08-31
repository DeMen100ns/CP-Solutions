/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

/*note:
- find_by_order(k): It returns to an iterator to the kth element (counting from zero)
- order_of_key(k) : It returns to the number of items that are strictly smaller than our item k
*/

#define ordered_set tree<long long, null_type, less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>

template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);

const long long N = 2e5 + 5;
const long long INF = 1e18 + 7;
const long long MAXA = 1e9;
const long long B = sqrt(N) + 5;

array <long long, 3> qu[N];
ordered_set s;
map <long long, long long> m;
long long fen[N], ct[N];

void upd(long long pos, long long val){
    for(long long i = pos; i < N; i += i & -i) fen[i] += val, ct[i]++;
}

pair<long long, long long> get(long long pos){
    pair<long long, long long> ans = {0, 0};
    for(long long i = pos; i; i -= i & -i) ans.first += fen[i], ans.second += ct[i];
    return ans;
}

void solve()
{
    long long q; cin >> q;
    for(long long i = 1; i <= q; ++i){
        cin >> qu[i][0];
        if (qu[i][0] == 1){
            cin >> qu[i][1] >> qu[i][2];
            s.insert(qu[i][1]);
        }
    }
    long long ct = 0, sum = 0, sumb = 0;
    for(long long i : s){
        ++ct; m[i] = ct;
    } ct = 0; s.clear();

    for(long long i = 1; i <= q; ++i){
        if (qu[i][0] == 1){
            ++ct; sum += qu[i][1];
            upd(m[qu[i][1]], qu[i][1]);
            s.insert(qu[i][1]);
            sumb += qu[i][2];
        } else {
            if (ct == 0){
                cout << 0; continue;
            }
            long long mid = (ct - 1) / 2;
            long long k = *s.find_by_order(mid);
            pair<long long, long long> state = get(m[k]);
            mid = state.second;
            long long firstmid = state.first;

            long long ans = (mid * k - firstmid) + ((sum - firstmid) - ((ct - mid) * k));

            cout << k << " " << ans + sumb << endl;
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

    int t = 1; // cin >> t;
    while (t--)
    {
        solve();
    }
}