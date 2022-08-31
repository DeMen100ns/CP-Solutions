/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long
#define ll long long
#define x first
#define y second
 
using namespace std;
 
/* Calculation with MODULO*/
 
const int MOD = 1e9 + 7;
 
ll dec(ll x, ll y, int mod = MOD) {return (x-y+mod)%mod;}
ll add(ll x, ll y, int mod = MOD) {return (x + y) % mod;}
ll mul(ll x, ll y, int mod = MOD) {return ((x%mod) * (y%mod)) % mod;}
ll bpow(ll x, ll y, int mod = MOD) {ll res = 1; while (y) {if (y & 1) res = mul(res, x, mod); x = mul(x, x, mod); y >>= 1;} return res;}
ll ModInverse(ll x, int mod = MOD) {return bpow(x, mod - 2, mod);}
ll Div(ll x, ll y, int mod = MOD) {return mul(x, ModInverse(y, mod), mod);}
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int N = 2e5 + 5;
int a[N], b[N], c[N];
set <int> s;
 
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int ma = 2;
    for(int i = 2; i <= n; ++i){
        int cur = a[i] - a[i - 1];
        if (cur == 0 && a[i - 1] - a[i - 2] == 0) continue;
        int cnt = 2;
        int j = i;
        while (1){
            int pos = lower_bound(a + 1, a + n + 1, a[i - 1] + 2 * cur) - a;
            pos = max(pos, j + 1);
            if (pos > n) break;
            cnt++;
            cur = a[pos] - a[i - 1];
            j = pos;
        }
        ma = max(ma, cnt);
    }
    cout << n - ma << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}