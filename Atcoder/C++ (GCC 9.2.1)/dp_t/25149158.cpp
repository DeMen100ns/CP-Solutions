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
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Os")

/*Weird define*/
#define ll long long
#define endl '\n'
#define gcd __gcd
#define ordered_set tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update>
//#define p prev
#define count1 __builtin_popcount

/*For define*/
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define foR(i,a,b) for(ll i=a;i>=b;i--)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define forN(i,a,b,c) for(ll i=a;i<=b;i+=c)
#define foRN(i,a,b,c) for(ll i=a;i>=b;i-=c)
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
typedef unsigned long long 	ull;
typedef vector<ll> 		vi;
typedef pair<ll, ll>		ii;
typedef long double         ld;

/*some const*/
const ll IMA = LLONG_MAX-10;
const ll IMI = LLONG_MIN+10;
const ll INF = INT_MAX;
const ll MOD = 1000000007;

/* Calculation with MODULO*/
ll dec(ll x, ll y) {return (x-y+MOD)%MOD;}
ll add(ll x, ll y) {return (x + y) % MOD;}
ll mul(ll x, ll y) {return ((x%MOD) * (y%MOD)) % MOD;}
ll bpow(ll x, ll y) {ll res = 1; while (y) {if (y & 1) res = mul(res, x); x = mul(x, x); y >>= 1;} return res;}
ll ModInverse(ll x) {return bpow(x, MOD - 2);}
ll Div(ll x, ll y) {return mul(x, ModInverse(y));}
ll GetBit(ll val, ll num) {return ((val>>num) & 1LL);}

/*Some simple checking and calculation function*/
string yn(bool k){if (k) return "YES"; else return "NO";}
ll binpower(ll base, ll e, ll mod) {ll result = 1;base %= mod;while (e){if (e & 1)result = (ll)result * base % mod;base = (ll)base * base % mod;e >>= 1;    }return result;}
bool check_composite(long long n, long long a, long long d, int s) {long long x = binpower(a, d, n); if (x == 1 or x == n - 1)return false;for (int r = 1; r < s; r++) {x = (long long)x * x % n;if (x == n - 1)return false;}return true;};
bool checkprime(long long n) {if (n < 2)return false;int r = 0;long long d = n - 1;while ((d & 1) == 0) {d >>= 1;r++;}for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {if (n == a)return true;if (check_composite(n, a, d, r))return false;}return true;}
bool checksqr(ll k){return (trunc(sqrt(k))*trunc(sqrt(k))==k);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
ll sum(ll n) {return n*(n+1)/2;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N=3e3+5;
int a[N], dp[N][N], pref[N][N];
string s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("E.INP","r",stdin);
    //freopen("E.out","w",stdout);
    int n;
    cin >> n;
    cin >> s;
    s="  "+s;
    dp[1][1]=1;
    For(j,1,n) pref[1][j]=1;
    For(i,2,n){
        For(j,1,i){
            if (s[i]=='>') dp[i][j]=add(dp[i][j],dec(pref[i-1][n],pref[i-1][j-1]));
            else dp[i][j]=add(dp[i][j],pref[i-1][j-1]);
        }
        For(j,1,n) pref[i][j]=add(pref[i][j-1],dp[i][j]);
    }
    cout << pref[n][n];
}
/*
//Delete define endl when interactive prolem

INPUT :
4 1
1 1 1 2

OUTPUT :

If it WA, check :
- Special case (Usually, n=1)
- WRONG FORMAT OUTPUT
- Check reading
- Change (ll) to (ull)
- lleger Overflow (The number that bigger than 2^63-1)
*/
