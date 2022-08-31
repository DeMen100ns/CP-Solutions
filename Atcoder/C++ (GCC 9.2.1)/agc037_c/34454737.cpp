/* header {{{1 */
#include <bits/stdc++.h>
using namespace std;

inline namespace dermus {
	void initio(string s = "test");
	void measure();
	void main();
}
int main() {
	return initio(), dermus::main(), measure(), 0;
}
namespace dermus {
#define tpl template
#define tpn typename
#define tp_ tpl<tpn... T
#define tpT tpl<tpn T
#define tpTU tpT, tpn U
#define tpT_ tpT, tpn... U
#define declret(...) -> decltype(__VA_ARGS__) { return __VA_ARGS__; }
#define type_trait(x, args...) \
	tpTU = void> struct x: false_type {}; \
	tpT> struct x<T, myvoid<decltype(args)>>: true_type {};

#define ft front()
#define bk back()
#define bg(x) begin(x)
#define ed(x) end(x)
#define sz(x) int((x).size())
#define all(x) bg(x), ed(x)
#define aln(x, n) ((x) + 1), ((x) + n + 1)
#define lb lower_bound
#define ub upper_bound
#define rsz resize
#define ins emplace
#define eb emplace_back
#define ef emplace_front
#define pb() pop_back()
#define pf() pop_front()
#define fi first
#define se second
#define mp make_pair
#define FOR(i, l, r) for (int i = (l), i##end = (r); i <= i##end; i++)
#define ROF(i, r, l) for (int i = (r), i##end = (l); i >= i##end; i--)
#define For(i, l, r) for (int i = (l), i##end = (r); i < i##end; i++)
#define Rof(i, r, l) for (int i = (r), i##end = (l); i > i##end; i--)
#define edge(i, v, u) for (int i = head[u], v = e[i].v; i; v = e[i = e[i].nxt].v)
#define each(a, x) for (auto &a: x)

tpT> using comp = complex<T>;
tp_> using mmap = multimap<T...>;
tp_> using ummap = unordered_multimap<T...>;
tp_> using mset = multiset<T...>;
tp_> using umset = unordered_multiset<T...>;
tp_> using umap = unordered_map<T...>;
tp_> using uset = unordered_set<T...>;
tp_> using pq = priority_queue<T...>;
tp_> using V = vector<T...>;
tpT> using pqg = pq<T, V<T>, greater<T>>;

using si = int;
using ui = unsigned;
using ll = long long;
using ul = unsigned long long;
using l3 = __int128_t;
using u3 = __uint128_t;
using db = double;
using ld = long double;
using pii = pair<int, int>;
using vi = V<int>;
using vpii = V<pii>;
using str = string;
#ifdef LOCAL
void setin(str a = "/dev/tty") { freopen(a.c_str(), "r", stdin); }
void setout(str a = "/dev/tty") { freopen(a.c_str(), "w", stdout); }
void measure() { system("grep VmPeak /proc/$PPID/status > /dev/tty"); }
#else
void setin(str = "") {}
void setout(str = "") {}
void measure() {}
#endif
void initio(str s) {
	setin(sz(s) ? s + ".in" : s), setout(sz(s) ? s + ".out" : s);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(13);
}

tpT> using myvoid = void;
tpl<bool F, tpn T = void> using enif = tpn enable_if<F, T>::type;
type_trait(is_ct, T().begin(), T().end());
type_trait(is_re, cin >> *(new T));
type_trait(is_wt, cout << T());

tpT> bool operator > (const T &a, const T &b) { return b < a; }
tpT> bool operator >= (const T &a, const T &b) { return !(a < b); }
tpT> bool operator <= (const T &a, const T &b) { return !(a > b); }
tpT> bool operator == (const T &a, const T &b) { return a >= b && a <= b; }
tpT> bool operator != (const T &a, const T &b) { return !(a == b); }
ll cdiv(ll x, ll y) { return x / y + ((x ^ y) > 0 && x % y); }
ll fdiv(ll x, ll y) { return x / y - ((x ^ y) < 0 && x % y); }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
tpTU> auto max(const T &x, const U &y) declret(x > y ? x : y)
tpTU> auto min(const T &x, const U &y) declret(x < y ? x : y)
tpTU> int chkmn(T &x, const U &y) { return y < x ? (x = y, 1) : 0; }
tpTU> int chkmx(T &x, const U &y) { return y > x ? (x = y, 1) : 0; }
ll popcnt(ll x) { return __builtin_popcountll(x); }
ll log2(ll x) { return x == 0 ? 0 : 63 - __builtin_clzll(x); }
ll pow2(ll x) { return x < 64 ? (1ll << x) : 0; }
ll msk2(ll x) { return pow2(x) - 1; }
ll lowbit(ll x) { return x & (-x); }

const ld INF = INFINITY, PI = acosl(-1);
const ll inf = 0x3f3f3f3f3f3f3f3f;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

#undef CLOCKS_PER_SEC
ll clock() { return chrono::steady_clock::now().time_since_epoch().count(); }
const ld CLOCKS_PER_SEC = 1.l * chrono::steady_clock::period::den /
	chrono::steady_clock::period::num;
mt19937 rng(clock());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

int gc() { return cin.get(); }
tpT> enif<is_re<T>::value> re(T &x) { cin >> x; }
void re(char *s) { cin >> s; }
void re(char &x) { while (isspace(x = gc())); }
tpTU> void re(pair<T, U> &pr) { re(pr.fi), re(pr.se); }
tpT> void re(comp<T> &a) { T x, y; re(x), re(y); a.real(x), a.imag(y); }
tpl<tpn T = ll> T re() { T ret; re(ret); return ret; }
tpT_> void re(T &&x, U&&... y) { re(x), re(y...); }
tpT> void ra(T l, T r) { while (l != r) re(*l++); }
tpT> void ra(T l, int n) { FOR (i, 1, n) re(l[i]); }
#define ints(...) ll __VA_ARGS__; re(__VA_ARGS__)

void pc(int x) { cout.put(x); }
#define fl cout << flush
#define sp pc(' ')
#define br pc('\n')
#define wts(...) wt(__VA_ARGS__), sp
#define wtb(...) wt(__VA_ARGS__), br
#define wte(...) wt(__VA_ARGS__), exit(0)
tpT> enif<is_wt<T>::value> wt(const T &x) { cout << x; }
tpTU> void wt(const pair<T, U> &pr) { wts(pr.fi), wt(pr.se); }
tpT> void wt(comp<T> &a) { wts(a.real()), wt(a.imag()); }
void wt(const char *s) { cout << s; }
void wt(str s) { cout << s; }
void wt() {}
tpT> void wa(T l, T r) { while (l != r) wts(*l++); }
tpT> void wa(T l, int n) { FOR (i, 1, n) wts(*++l); }
tpT> enif<is_ct<T>::value> wt(const T &x) { wa(BE(x)); }
tpT_> void wt(const T &x, const U&... y) { wts(x), wt(y...); }
/* modint {{{1 */
#define mint_body(mi) \
	static ui up(ui x) { return (x >> 31 & 1) ? x + M : x; } \
	static ui dn(ui x) { return x < M ? x : x - M; } \
	ui x; \
	mi(): x() {} \
	mi(ll y) { x = y < 0 ? up(-mod(-y)) : mod(y); } \
	explicit operator int() const { return x; } \
	friend void re(mi &a) { a = re<ll>(); } \
	friend void wt(mi a) { wt(a.x); } \
	friend bool operator == (const mi &a, const mi &b) { return a.x == b.x; } \
	friend mi pow(mi x, ul y) { \
		mi ans = 1; \
		for (; y; y >>= 1, x *= x) if (y & 1) ans *= x; \
		return ans; \
	} \
	mi inv() const { assert(x); return pow(*this, M - 2); } \
	mi operator - () const { mi x = *this; x.x = up(-x.x); return x; } \
	mi &operator += (mi y) { return x = dn(x + y.x), *this; } \
	mi &operator -= (mi y) { return x = up(x - y.x), *this; } \
	mi &operator *= (mi y) { return x = mod((ul)x * y.x), *this; } \
	mi &operator /= (mi y) { return *this *= y.inv(); } \
	friend mi operator + (mi x, mi y) { return x += y; } \
	friend mi operator - (mi x, mi y) { return x -= y; } \
	friend mi operator * (mi x, mi y) { return x *= y; } \
	friend mi operator / (mi x, mi y) { return x /= y; }
tpl<ui Mod, ui Root = 3>
struct mint {
	static const ui M = Mod, RT = Root;
	static ui mod(ul x) { return x % M; }
	mint_body(mint);
};
tpl<int ID = 0>
struct mint_fast {
	static ui M, RT;
	static ul B;
	static void init(ui Mod, ui Root = 3) { M = Mod, RT = Root, B = (1ull << 63) / M; }
	static ui mod(ul x) { return dn(x - (((u3)x * B) >> 63) * M); }
	mint_body(mint_fast);
};
tpl<int ID> ui mint_fast<ID>::M;
tpl<int ID> ui mint_fast<ID>::RT;
tpl<int ID> ul mint_fast<ID>::B;

using m998 = mint<998244353>;
using m197 = mint<1000000007, 5>;
/* }}} */

const int N = 200100;
int n, a[N], b[N], vis[N];
bool chk(int x) {
	return b[x] - a[x] >= b[(x + n - 1) % n] + b[(x + 1) % n];
}

void main() {
	re(n), ra(a, a + n), ra(b, b + n);
	queue<int> q;
	For (i, 0, n) if (chk(i)) q.push(i), vis[i] = 1;
	ll ans = 0;
	while (!q.empty()) {
		int y = q.ft, x = (y + n - 1) % n, z = (y + 1) % n; q.pop();
		int cnt = (b[y] - a[y]) / (b[x] + b[z]);
		b[y] -= cnt * (b[x] + b[z]), ans += cnt, vis[y] = 0;
		if (!vis[x] && chk(x)) q.push(x), vis[x] = 1;
		if (!vis[z] && chk(z)) q.push(z), vis[z] = 1;
	}
	For (i, 0, n) if (b[i] != a[i]) wte(-1);
	wtb(ans);
}
} /* end of namespace */