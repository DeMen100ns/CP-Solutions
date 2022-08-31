/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;
void add(int &a, int b, int mod = MOD){ a += b; while (a < 0) a += mod; while (a >= mod) a -= mod; }
int sum(int a, int b, int mod = MOD){ return add(a, b, mod), a; }
void mul(int &a, int b, int mod = MOD){ a = (a * 1LL * b) % mod; }
int prod(int a, int b, int mod = MOD){ return mul(a, b, mod), a; }
int bpow(int a, int b, int mod = MOD){ int ans = 1; while (b){ if (b & 1){ mul(ans, a, mod); } mul(a, a, mod); b >>= 1; } return ans; }
int Inv(int a, int mod = MOD){ return bpow(a, mod - 2, mod); }
int Div(int a, int b, int mod = MOD) { return prod(a, Inv(b, mod), mod); }

const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e5;
const int B = sqrt(N) + 5;

pair<int, int> a[N];

int msb(int n){
    for(int i = 1; i <= 16; i <<= 1){
        n |= (n >> i);
    }
    return (n + 1) >> 1;
}

int cal(int n, int k, int cur){
    if (k == 0) return 0;
    int msbk = msb(k);
    int c = cur ^ (msbk - 1);
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= n; ++i){
        if ((c & a[i].first) == a[i].first)
            ans1 += a[i].second;
    }
    for(int i = 1; i <= n; ++i){
        if ((k & a[i].first) == a[i].first){
            ans2 += a[i].second;
        }
    }
    int ans3 = 0;
    ans3 = cal(n, k ^ msbk, cur ^ msbk);
    return max({ans1, ans2, ans3});
}

void solve()
{
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
    if (k == 0){
        int ans = 0;
        for(int i = 1; i <= n; ++i) ans += a[i].second * (a[i].first == 0);
        cout << ans; return;
    }
    cout << cal(n, k, 0);
    //k = 14_10 = 1110_2
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	//freopen("checklist.in", "r", stdin);
	//freopen("checklist.out", "w", stdout);

    int t = 1; //cin >> t;
    while (t--)
    {
        solve();
    }
}