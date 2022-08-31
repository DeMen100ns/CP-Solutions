/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

/*
Day start : 09/06/2022
To - day  : 14/06/2022
Counting : 0011
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

const int N = 50 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int a[N], b[N], d[N][N], n;

bool check(int cur){
    for(int i = 0; i <= 50; ++i){
        for(int j = 0; j <= 50; ++j){
            if (i != j) d[i][j] = INF;
        }
    }
    for(int i = 1; i <= 50; ++i){
        for(int m = 1; m <= i; ++m){
            if (!(cur & (1LL << (m - 1)))) continue;
            d[i][i % m] = min(d[i][i % m], (1LL << m));
        }
    }
    for(int i = 0; i <= 50; ++i){
        for(int j = 0; j <= 50; ++j){
            for(int k = 0; k <= 50; ++k){
                d[i][k] = min(d[i][k], d[i][j] + d[j][k]);
            }
        }
    }
    /*for(int i = 0; i <= 50; ++i){
        for(int j = 0; j <= i; ++j){
            bitset <50> bs = d[i][j];
            cout << bs << " ";
        } cout << endl;
    }*/
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if (d[a[i]][b[i]] == INF){
            return false;
        }
    }
    return true;
}

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    int cur = (1LL << 50) - 1, j = 49;
    while (j >= 0){
        cur ^= (1LL << j);
        if (!check(cur)) cur ^= (1LL << j);
        --j;
    }
    if (!check(cur)){
        cout << -1;
    } else cout << cur * 2;
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