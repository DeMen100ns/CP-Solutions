/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
#include <algorithm>
#include <cassert>
#include <vector>
 
 
#ifdef _MSC_VER
#include <intrin.h>
#endif
 
namespace atcoder {
 
namespace internal {
 
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}
 
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}
 
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}
 
}  // namespace internal
 
}  // namespace atcoder
 
 
namespace atcoder {
 
template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }
 
    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
 
    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }
 
    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;
 
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
 
    S all_prod() const { return d[1]; }
 
    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }
 
    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
 
  private:
    int _n, size, log;
    std::vector<S> d;
 
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
 
}  // namespace atcoder
 
 
using namespace std;
using namespace atcoder;
 
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
 
const int N = 5e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int op(int a, int b){
    return max(a, b);
}
 
int e(){
    return 0;
}
 
int u[N], v[N], p[N], pq[N], sub[N], pos[N], val[N], head[N];
int n, m, q;
bool f[N];
array<int, 2> qu[N];
vector <int> a[N], vq, euler;
segtree<int, op, e> seg(N);
 
int root(int u){
    if (p[u] == u) return u;
    else return p[u] = root(p[u]);
}
 
void Union(int u, int v){
    u = root(u), v = root(v);
    if (u == v) return;
    p[v] = u;
    a[u].push_back(v);
}
 
void Add(int u, int v){
    u = root(u), v = root(v); ++n;
    p[n] = p[u] = p[v] = n;
    a[n].push_back(u);
    if (u == v) return;
    a[n].push_back(v);
}
 
void dfs_euler(int u, int par = 0){
    euler.push_back(u);
    pos[u] = euler.size();
    for(int i : a[u]){
        if (i == par) continue;
        dfs_euler(i, u);
        sub[u] += sub[i];
    }
    sub[u]++;
}
 
void solve()
{
    cin >> n >> m >> q; int n1 = n;
    for(int i = 1; i <= n; ++i) {
        cin >> val[i];
        head[val[i]] = i;
    }
    iota(p + 1, p + n + 1, 1);
    for(int i = 1; i <= m; ++i) cin >> u[i] >> v[i];
    for(int i = 1; i <= q; ++i) {
        int type, v; cin >> type >> v;
        if (type == 2) f[v] = true;
        qu[i] = {type, v};
    }
 
    reverse(vq.begin(), vq.end());
 
    for(int i = 1; i <= m; ++i){
        if (!f[i]) {
            Add(u[i], v[i]);
        }
    }
    for(int i = q; i; --i){
        int type = qu[i][0], p = qu[i][1];
        if (type == 1){
            pq[i] = root(p);
        }
        else Add(u[p], v[p]);
    }
 
    for(int i = 1; i <= n; ++i){
        if (p[i] == i) dfs_euler(i);
    }
 
    for(int i = 1; i <= n1; ++i){
        seg.set(pos[i], val[i]);
    }
 
    for(int i = 1; i <= q; ++i){
        int type = qu[i][0];
        if (type == 1){
            int u = pq[i];
            int ans = seg.prod(pos[u], pos[u] + sub[u]);
            cout << ans << endl;
            if (ans) seg.set(pos[head[ans]], 0);
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