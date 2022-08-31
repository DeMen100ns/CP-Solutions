//Author : Trieu self-destruct
//TST next year

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//using namespace __gnu_pbds;

using namespace std;

/*Pragma*/
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O3")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Os")

/*Weird define*/
#define endl '\n'
#define gcd __gcd
#define count1 __builtin_popcount
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//#define p prev

/*For define*/
#define For(i,a,b) for(int i=a;i<=b;i++)
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
typedef long long ll;
typedef unsigned long long 	ull;
typedef vector<ll> 		vi;
typedef pair<ll, ll>		ii;
typedef long double         ld;

/*some const*/
const ll IMA = LLONG_MAX-10;
const ll IMI = LLONG_MIN+10;
const ll INF = INT_MAX-10;
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
string yn(bool k){if (k) return "Yes"; else return "No";}
ll binpower(ll base, ll e, ll mod) {ll result = 1;base %= mod;while (e){if (e & 1)result = (ll)result * base % mod;base = (ll)base * base % mod;e >>= 1;    }return result;}
bool check_composite(long long n, long long a, long long d, int s) {long long x = binpower(a, d, n); if (x == 1 || x == n - 1)return false;for (int r = 1; r < s; r++) {x = (long long)x * x % n;if (x == n - 1)return false;}return true;};
bool checkprime(long long n) {if (n < 2)return false;int r = 0;long long d = n - 1;while ((d & 1) == 0) {d >>= 1;r++;}for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {if (n == a)return true;if (check_composite(n, a, d, r))return false;}return true;}
bool checksqr(ll k){return (trunc(sqrt(k))*trunc(sqrt(k))==k);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}

const int N=1+20;
ll a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ll n,k;
 //   int n=3;
    For(i,1,3) cin >> a[i];
    sort(a+1,a+4);
  //  write(a,1,3);
    if (a[1]==a[2]) cout << a[3];
    else {
        if (a[2]==a[3]) cout << a[1];
        else cout << 0;
    }
    return 0;
}
/*
//Delete define endl when interactive prolem

INPUT :
3
-3 -2 7 1 -3 -7 -3 5
6 9 -1 -3 -8 9 9 2
7 -7 -3 4 -4 -8 -2 4
OUTPUT :

If it WA, check :
- Special case (Usually, n=1)
- WRONG FORMAT OUTPUT
- Check reading
- Change (ll) to (ull)
- lleger Overflow (The number that bigger than 2^63-1)
*/
