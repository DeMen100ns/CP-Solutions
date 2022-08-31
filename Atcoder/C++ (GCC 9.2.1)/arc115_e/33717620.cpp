/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/

#include <bits/stdc++.h>

using namespace std;

template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);

const int MOD = 998244353;

inline void add(int &x, int y) { x += y; while (x >= MOD) x -= MOD; while (x < 0) x += MOD; }
inline void mul(int &x, int y) { x = (x * 1LL * y) % MOD; }
inline int prod(int x, int y) { return mul(x, y), x; }
inline int sum(int x, int y) { return add(x, y), x; }
inline int bpow(int x, int y) { int ans = 1; while (y) { if (y & 1) mul(ans, x); mul(x, x); y >>= 1; } return ans; }
inline int Inv(int x) { return bpow(x, MOD - 2); }
inline int Div(int x, int y) { return prod(x, Inv(y)); }

const int N = 5e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int seg[40 * N], L[40 * N], R[40 * N];
int lazy1[40 * N], lazy2[40 * N];
int cnt = 1;

void down(int id, int l, int r){
	int mid = (l + r) >> 1;

	int t = lazy2[id];
	int m = lazy1[id];

	lazy1[L[id]] *= m; lazy1[R[id]] *= m;
	lazy2[L[id]] *= m; lazy2[R[id]] *= m;

	seg[L[id]] *= m; seg[L[id]] = sum(seg[L[id]], 0);
	seg[R[id]] *= m; seg[R[id]] = sum(seg[R[id]], 0);

	lazy2[L[id]] = sum(lazy2[L[id]], t);
	lazy2[R[id]] = sum(lazy2[R[id]], t);

	seg[L[id]] = sum(seg[L[id]], prod(t, mid - l + 1));
	seg[R[id]] = sum(seg[R[id]], prod(t, r - mid));

	lazy1[id] = 1;
	lazy2[id] = 0;
}

void upd(int id, int l, int r, int u, int v, int val, int type){
	if (l > v || r < u) return;
	if (l >= u && r <= v){
		if (type == 0){
			seg[id] *= val;
			seg[id] = sum(seg[id], MOD);
			lazy1[id] *= val;
			lazy2[id] *= val;
			lazy2[id] = sum(lazy2[id], MOD);
		} else {
			seg[id] = sum(prod(val, r - l + 1), seg[id]);
			lazy2[id] = sum(lazy2[id], val);
		}
		return;
	}
	if (!L[id]){
		L[id] = ++cnt;
	}
	if (!R[id]){
		R[id] = ++cnt;
	}
	down(id, l, r);
	int mid = (l + r) >> 1;
	upd(L[id], l, mid, u, v, val, type);
	upd(R[id], mid + 1, r, u, v, val, type);
	seg[id] = sum(seg[L[id]], seg[R[id]]);
}

int get(int id, int l, int r, int pos){
	if (l == r && r == pos){
		return seg[id];
	}
	if (!L[id]){
		L[id] = ++cnt;
	}
	if (!R[id]){
		R[id] = ++cnt;
	}
	down(id, l, r);
	int mid = (l + r) >> 1;
	if (pos <= mid) return get(L[id], l, mid, pos);
	else return get(R[id], mid + 1, r, pos);
}

void debug(int x){
	for(int i = 1; i <= x; ++i){
		cout << get(1, 1, MAXA, i) << " ";
	} cout << endl;
}

void solve(){
	int n;
	cin >> n;
	int x; cin >> x;
	upd(1, 1, MAXA, 1, x, 1, 1);
	//debug(2);
	for(int i = 2; i <= n; ++i){
		int x;
		cin >> x;
		int s = seg[1];
		upd(1, 1, MAXA, 1, x, -1, 0);
		upd(1, 1, MAXA, 1, x, s, 1);
		upd(1, 1, MAXA, x + 1, MAXA, 0, 0);
		//debug(x);
	}
	cout << seg[1];
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