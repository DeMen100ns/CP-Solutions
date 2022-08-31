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
    int n2, n = 0;
    cin >> n2;
    int ans = bpow(2, n2);
    for(int i = 1; i <= n2; ++i){
        cin >> a[i];
        if (a[i] % 2 == 0) b[++n] = a[i];//, cout << a[i] << " ";
    } //cout << endl;
    for(int i = 1; i <= n; ++i){
        int cnt = 0;
        while (b[i] % 2 == 0){
            b[i] /= 2;
            cnt++;
        }
        c[cnt]++;
    }
    for(int i = 31; i >= 1; --i) {
        c[i] += c[i + 1];
        //cout << c[i] << " ";
        if (c[i] > 0) s.insert(c[i] - 1);
    }
    ans = dec(ans, 1);
    for(auto i : s){
        ans = dec(ans, bpow(2, i));
    }
    cout << ans;
    //2 4
    //4 8
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; //cin >> t;
    while (t--){
        solve();
    }
}