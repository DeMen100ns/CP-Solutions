/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
/*Pragma*/
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O3")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Os")
//#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
 
/*Normal define*/
//#define int long long
#define ll long long
//#define endl '\n'
#define gcd __gcd
#define ordered_set tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update>
//#define p prev
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define count1 __builtin_popcountll
 
/*For define*/
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define foR(i,a,b) for(ll i=a;i>=b;i--)
#define fora(i, a) for (auto i : a)
 
/*push-pop-pair define*/
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define x first
#define y second
 
/*Print define*/
#define write(a, l, r) for (ll ik = l; ik <= r; ik++) cout << a[ik] << ' '; cout << endl
#define writeln(a, l, r) for (ll ik = l; ik <= r; ik++) cout << a[ik] << endl
 
/*Type-def*/
typedef unsigned long long  ull;
typedef vector<ll>      vi;
typedef pair<int, int>        ii;
typedef long double         ld;
 
/* Calculation with MODULO*/
 
const int MOD = 1e9 + 7;
 
ll dec(ll x, ll y, int mod = MOD) {return (x-y+mod)%mod;}
ll add(ll x, ll y, int mod = MOD) {return (x + y) % mod;}
ll mul(ll x, ll y, int mod = MOD) {return ((x%mod) * (y%mod)) % mod;}
ll bpow(ll x, ll y, int mod = MOD) {ll res = 1; while (y) {if (y & 1) res = mul(res, x, mod); x = mul(x, x, mod); y >>= 1;} return res;}
ll ModInverse(ll x, int mod = MOD) {return bpow(x, mod - 2, mod);}
ll Div(ll x, ll y, int mod = MOD) {return mul(x, ModInverse(y, mod), mod);}
bool GetBit(int val, int num) {return ((val>>num) & 1);}
 
/*Some simple checking and calculation function*/
string yn(bool k){if (k) return "YES"; else return "NO";}
__int128 binpower(__int128 base, __int128 e, __int128 mod) {__int128 result = 1;base %= mod;while (e){if (e & 1)result = (__int128)result * base % mod;base = (__int128)base * base % mod;e >>= 1;    }return result;}
bool check_composite(__int128 n, __int128 a, __int128 d, int s) {__int128 x = binpower(a, d, n); if (x == 1 or x == n - 1)return false;for (int r = 1; r < s; r++) {x = (__int128)x * x % n;if (x == n - 1)return false;}return true;};
bool checkprime(__int128 n) {if (n < 2)return false;int r = 0;__int128 d = n - 1;while ((d & 1) == 0) {d >>= 1;r++;}for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {if (n == a)return true;if (check_composite(n, a, d, r))return false;}return true;}
bool checksqr(ll k){return (trunc(sqrt(k))*trunc(sqrt(k))==k);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
ll sum(ll n) {return n*(n+1)/2;}
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int N = 2e5 + 5;
const ll INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
vector <int> a[N];
bool f[N];
int n, m, d;
int ma[N], ans[N], h[N], dis[N], dis_oth[N], pref[N], suf[N];
 
void dfs(int u, int par = 0){
    fora(i, a[u]){
        if (i == par) continue;
        h[i] = h[u] + 1;
        dfs(i, u);
        ma[u] = max(ma[u], ma[i]);
    }
    if (f[u]) ma[u] = max(ma[u], h[u]);
    dis[u] = ma[u] - h[u];
    if (ma[u] == 0) dis[u] = -N;
}
 
void dfs_reroot(int u, int par = 0){
    if (a[u].empty()) return;
    int len = a[u].size();
    pref[0] = dis[a[u][0]];
    if (a[u][0] == par) pref[0] = -N;
    For(i,1,len - 1){
        int v = a[u][i];
        if (v == par){
            pref[i] = pref[i - 1];
            continue;
        }
        pref[i] = max(pref[i - 1], dis[v]);
    }
    suf[len - 1] = dis[a[u][len - 1]];
    if (a[u][len - 1] == par) suf[len - 1] = -N;
    foR(i,len - 2, 0){
        int v = a[u][i];
        if (v == par){
            suf[i] = suf[i + 1];
            continue;
        }
        suf[i] = max(suf[i + 1], dis[v]);
    }
    For(i, 0, len - 1){
        int ans1 = -N, ans2 = -N;
        int v = a[u][i];
        if (v == par) continue;
        if (i) ans1 = pref[i - 1];
        if (i < len - 1) ans2 = suf[i + 1];
        //cout << v << " " << ans1 << " " << ans2 << endl;
        dis_oth[v] = max({dis_oth[u], ans1 + 1, ans2 + 1}) + 1;
        if (f[u]) dis_oth[v] = max(dis_oth[v], 1);
        ans[v] = max(dis[v], dis_oth[v]);
        //dfs_reroot(v, u);
    }
    fora(i, a[u]){
        if (i == par) continue;
        dfs_reroot(i, u);
    }
}
 
void solve(){
    cin >> n >> m >> d;
    For(i,1,n) dis_oth[i] = -N; //:)))
    For(i,1,m) {int x; cin >> x; f[x] = true;}
    For(i,1,n - 1){
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    h[1] = 1;
    dfs(1);
    ans[1] = dis[1];
    dfs_reroot(1);
    int cnt = 0;
    For(i,1,n) cnt += ((ans[i] <= d));
    /*write(ma,1,n);
    write(dis,1,n);
    write(dis_oth,1,n);
    write(ans,1,n);*/
    cout << cnt;
}
 
signed main(){
    FastIO
    //freopen("codeforces.inp","r",stdin);
    //freopen("codeforces.out","w",stdout);
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
}
/*
//Delete define endl when interactive prolem
 
INPUT :
4 10
0 1 6 5
1 1 3 4
2 2 2 1
3 4 4
2 1 2 4
2 2 4 1
2 1 4 7
2 2 4 2
3 1 4
1 1 2 1
2 3 3 4
 
OUTPUT :
5
7
 
If it WA, check :
- Special case (Usually, n=1)
- WRONG FORMAT OUTPUT
- Check reading
- Change (ll) to (ull)
- lleger Overflow (The number that bigger than 2^63-1)
*/