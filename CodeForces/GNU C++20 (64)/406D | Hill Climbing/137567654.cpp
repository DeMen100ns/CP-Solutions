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
#define int long long
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
 
const int N = 1e5 + 5;
const ll INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
ii a[N];
int nxt[N][22], h[N];
 
int dis(int l, int r){
    int cnt = 0;
    while (l < r){
        int p = 20;
        For(i,0,20){
            if (nxt[l][i] > r){
                p = i - 1;
                break;
            }
        }
        l = nxt[l][p];
        cnt += (1 << p);
    }
    return cnt;
}
 
int S(ii a, ii b, ii c){
    return (b.x - a.x) * (a.y + b.y) +
    (c.x - b.x) * (b.y + c.y) + (a.x - c.x) * (c.y + a.y);
}
 
int lca(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    foR(i,20,0){
        if (h[u] - (1 << i) >= h[v]){
            u = nxt[u][i];
        }
    }
    if (u == v) return u;
    foR(i,20,0){
        if (nxt[u][i] != nxt[v][i]){
            u = nxt[u][i];
            v = nxt[v][i];
        }
    }
    return nxt[u][0];
}
 
void solve(){
    int n, m;
    cin >> n;
    For(i,1,n){
        cin >> a[i].x >> a[i].y;
    }
    vector <int> up;
    nxt[n][0] = n;
    up.pb(n);
    foR(i, n - 1, 1){
        int k = up.size();
        while (k >= 2 && S(a[up[k - 2]], a[up[k - 1]], a[i]) > 0) up.pob(), k--;
        nxt[i][0] = up.back();
        h[i] = h[nxt[i][0]] + 1;
        up.pb(i);
    }
    For(j,1,20){
        foR(i,n,1){
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
        }
    }
    //write(h,1,n);
    cin >> m;
    while (m--){
        int l, r;
        bool f = false;
        cin >> l >> r;
        cout << lca(l, r) << " ";
    }
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