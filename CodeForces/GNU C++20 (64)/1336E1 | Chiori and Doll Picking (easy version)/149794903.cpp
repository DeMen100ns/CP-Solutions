/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 3e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
const int MOD = 998244353;
 
vector <int> basis, basisl, basisr; 
vector <int> r[N];
vector <pair<int, int>> v[40];
int a[N], ans[N], f[N], g[N];
 
int fpow(int n, long long k, int p = (int) 1e9 + 7) {
    int r = 1;
    for (; k; k >>= 1) {
        if (k & 1) r = (long long) r * n % p;
        n = (long long) n * n % p;
    }
    return r;
}
 
void XORFFT(int a[], int n, int p, int invert) {
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i; k++) {
                int u = a[j + k], v = a[i + j + k];
                a[j + k] = u + v;
                if (a[j + k] >= p) a[j + k] -= p;
                a[i + j + k] = u - v;
                if (a[i + j + k] < 0) a[i + j + k] += p;
            }
        }
    }
    if (invert) {
        long long inv = fpow(n, p - 2, p);
        for (int i = 0; i < n; i++) a[i] = a[i] * inv % p;
    }
}
 
void ins(int a){
 for(int i : basis){
  a = min(a, a ^ i);
 }
    if (a) basis.push_back(a);
}
 
bool check(int a){
    for(int i : basis){
        a = min(a, a ^ i);
    }
    return (a == 0);
}
 
void solve(){
    int n, m, p = 1; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if (check(a[i])) p *= 2;
        else ins(a[i]);
        p %= MOD;
    }
    int mid = (m + 1) / 2;
    int mask1 = (1LL << mid) - 1;
    int mask2 = ((1LL << m) - 1) ^ mask1;
    for(int i : basis){
        if (log2(i) < mid) basisl.push_back(i);
        else basisr.push_back(i);
    }
    for(int i = 0; i < (1 << basisl.size()); ++i){
        int sum = 0;
        for(int j = 0; j < basisl.size(); ++j){
            if (i >> j & 1){
                sum ^= basisl[j];
            }
        }
        f[sum]++;
    }
    XORFFT(f, 1LL << mid, MOD, 0);
    for(int i = 0; i < (1 << basisr.size()); ++i){
        int sum = 0;
        for(int j = 0; j < basisr.size(); ++j){
            if (i >> j & 1){
                sum ^= basisr[j];
            }
        }
        r[__builtin_popcountll(sum & mask2)].push_back(sum & mask1);
    }
    for(int i = 0; i <= mid; ++i){
        memset(g, 0, sizeof g);
        for(int v : r[i]) g[v]++;
        XORFFT(g, 1LL << mid, MOD, 0);
        for(int j = 0; j < (1LL << mid); ++j){
            g[j] = (f[j] * g[j]) % MOD;
        }
        XORFFT(g, 1LL << mid, MOD, 1);
        for(int j = 0; j < (1 << mid); ++j){
            ans[i + __builtin_popcountll(j)] += g[j];
        }
    }
    for(int i = 0; i <= m; ++i){
        cout << (ans[i] * p) % MOD << " ";
    }
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
    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}