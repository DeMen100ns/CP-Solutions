/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
long long dec(long long x, long long y, int mod = MOD) {return (x-y+mod)%mod;}
long long add(long long x, long long y, int mod = MOD) {return (x + y) % mod;}
long long mul(long long x, long long y, int mod = MOD) {return ((x%mod) * (y%mod)) % mod;}
long long bpow(long long x, long long y, int mod = MOD) {long long res = 1; while (y) {if (y & 1) res = mul(res, x, mod); x = mul(x, x, mod); y >>= 1;} return res;}
long long ModInverse(long long x, int mod = MOD) {return bpow(x, mod - 2, mod);}
long long Div(long long x, long long y, int mod = MOD) {return mul(x, ModInverse(y, mod), mod);}
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], gt[N];
 
int C(int k, int n){
    if (k > n) return 0;
    return Div(gt[n], mul(gt[n - k], gt[k]));
}
 
void solve(){
    int n, T;
 cin >> n >> T;
    gt[0] = 1;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        gt[i] = mul(gt[i - 1], i);
    }
    int s = 0, ans = 0, j = n, curc = 0;
    bool f = true;
    for(int i = 1; i <= n; ++i){
        s += a[i];
        if (s > T) break;
        if (s + i <= T){
            ans++;
            continue;
        }
        int k = T - s;
        //2 * (C(0, i) + ... + C(k, i)) + C(k + 1, i)
        //= C(0, i + 1) + .. + C(k, i + 1)
        if (f){
            j = k;
            for(int p = 0; p <= k; ++p){
                curc = add(curc, C(p, i));
            }
            f = false;
        } else {
            curc = add(mul(curc, 2), C(j + 1, i - 1));
            ++j;
            while (j > k){
                curc = dec(curc, C(j, i));
                --j;
            }
        }
        ans = add(ans, Div(curc, bpow(2, i)));
    }
    cout << ans;
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