#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

#define int long long
#define ii pair<int, int>

using namespace std;

template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);

const int N = 2e5 + 5;
const int base = 311;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const long long INF = 1e18 + 7;

int dec(int x, int y, int mod = MOD) {return (x-y+mod)%mod;}
int add(int x, int y, int mod = MOD) {return (x + y) % mod;}
int mul(int x, int y, int mod = MOD) {return ((x%mod) * (y%mod)) % mod;}
int bpow(int x, int y, int mod = MOD) {int res = 1; while (y) {if (y & 1) res = mul(res, x, mod); x = mul(x, x, mod); y >>= 1;} return res;}
int ModInverse(int x, int mod = MOD) {return bpow(x, mod - 2, mod);}
int Div(int x, int y, int mod = MOD) {return mul(x, ModInverse(y, mod), mod);}

int seg[4 * N];
array <int, 3> lazy[4 * N];

void down(int id, int l, int r){
	int mid = (l + r) >> 1;
	array <int, 3> t = lazy[id];
	//cout << endl;
	//cout << t[0] << " " << t[1] << " " << t[2] << endl;
	if (t[2] != 0){
		lazy[id << 1][2] = lazy[id << 1 | 1][2] = t[2];
		seg[id << 1] = t[2] * (mid - l + 1);
		seg[id << 1 | 1] = t[2] * (r - mid);
		lazy[id << 1][1] = lazy[id << 1 | 1][1] = 1;
		lazy[id << 1][0] = lazy[id << 1 | 1][0] = 0;
	}
	lazy[id] = {0, 1, 0};
	return;
}

void upd_assign(int id, int l, int r, int u, int v, int val){
	if (l > v || r < u || l > r || u > v) return;
	if (l >= u && r <= v){
		seg[id] = val * (r - l + 1);
		lazy[id][2] = val;
		lazy[id][0] = 0;
		lazy[id][1] = 1;
		return;
	}
	down(id, l, r);
	int mid = (l + r) >> 1;
	upd_assign(id << 1, l, mid, u, v, val);
	upd_assign(id << 1 | 1, mid + 1, r, u, v, val);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

int get(int id, int l, int r, int u, int v){
	if (l > v || r < u) return 0;
	if (l >= u && r <= v){
		return seg[id];
	}
	down(id, l, r);
	int mid = (l + r) >> 1;
	int v1 = get(id << 1, l, mid, u, v);
	int v2 = get(id << 1 | 1, mid + 1, r, u, v);
	return v1 + v2;
}

void solve(){
	int n, q, x;
	cin >> n >> q >> x;
	for(int i = 1; i <= 4 * n; ++i) lazy[i][1] = 1;
	for(int i = 1; i <= n; ++i){
		int k;
		cin >> k;
        if (k < x) k = -2;
        else if (k == x) k = 1;
        else k = 2;
		upd_assign(1, 1, n, i, i, k);
	}

	while (q--){
		int type, l, r;
		cin >> type >> l >> r;
		
        int s = get(1, 1, n, l, r);
        array<int, 3> cnt, val = {-2, 1, 2};
        cnt[1] = (s % 2 != 0); s -= cnt[1];

        s /= 2;
        int len = (r - l + 1) - cnt[1];
        cnt[2] = (s + len) / 2;
        cnt[0] = (len - s) / 2;

        //s = -3, len = 5

        if (type == 1){
            for(int k = 0; k < 3; l += cnt[k], ++k){
                upd_assign(1, 1, n, l, l + cnt[k] - 1, val[k]);
            }
        } else {
            for(int k = 0; k < 3; r -= cnt[k], ++k){
                upd_assign(1, 1, n, r - cnt[k] + 1, r, val[k]);
            }
        }

	}
    for(int i = 1; i <= n; ++i){
        //cout << get(1, 1, n, i, i) << " ";
        if (get(1, 1, n, i, i) == 1) cout << i;
    }
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//freopen("QN.inp","r",stdin);
	//freopen("QN.out","w",stdout);

	int t = 1; //cin >> t;
	while (t--){
		solve();
	}
	
	return 0;
}
