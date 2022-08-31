/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
//using namespace __gnu_pbds;
using namespace std;
 
/*Pragma*/
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Os")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
 
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
ll binpower(ll base, ll e, ll mod) {ll result = 1;base %= mod;while (e){if (e & 1)result = (ll)result * base % mod;base = (ll)base * base % mod;e >>= 1;    }return result;}
bool check_composite(ll n, ll a, ll d, int s) {ll x = binpower(a, d, n); if (x == 1 or x == n - 1)return false;for (int r = 1; r < s; r++) {x = (ll)x * x % n;if (x == n - 1)return false;}return true;};
bool checkprime(ll n) {if (n < 2)return false;int r = 0;ll d = n - 1;while ((d & 1) == 0) {d >>= 1;r++;}for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {if (n == a)return true;if (check_composite(n, a, d, r))return false;}return true;}
bool checksqr(ll k){return (trunc(sqrt(k))*trunc(sqrt(k))==k);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
ll sum(ll n) {return n*(n+1)/2;}
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int N = 1e4 + 5;
const int M = 1e5 + 5;
 
array <int, 3> edge[M];
vector <int> a[N];
bool f[N], ml[N];
int mr[N];
 
bool dfs(int u){
    f[u] = true;
    fora(i, a[u]){
        if (f[mr[i]]) continue;
        if (!mr[i] || dfs(mr[i])){
            mr[i] = u;
            return true;
        }
    }
    return false;
}
 
int max_matching(int n){
    int cnt = 0;
    For(i,1,n) shuffle(a[i].begin(), a[i].end(), rng);
    For(i,1,n){
        fora(j,a[i]){
            if (!mr[j]){
                mr[j] = i;
                ml[i] = true;
                ++cnt;
                break;
            }
        }
    }
    for(bool run = 1; run;){
        For(i,1,n) f[i] = false;
        run = 0;
        For(i,1,n){
            if (ml[i]) continue;
            if (dfs(i)) ml[i] = true, ++cnt, run = 1;
        }
    }
    return cnt;
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    For(i,1,m){
        int u, v, w;
        cin >> edge[i][1] >> edge[i][2] >> edge[i][0];
    }
    sort(edge + 1, edge + m + 1);
    int l = 0, r = m + 1;
    while (l + 1 < r){
        int mid = (l + r) >> 1;
        For(i,1,n) a[i].clear(), f[i] = mr[i] = ml[i] = 0;
        For(i,1,mid){
            a[edge[i][1]].pb(edge[i][2]);
        }
        if (max_matching(n) == n){
            r = mid;
        } else l = mid;
    }
    if (r <= m) cout << edge[r][0];
    else cout << -1;
}
 
signed main(){
    //FastIO
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