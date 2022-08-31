/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

/*
Day start : 09/06/2022
To - day  : 14/06/2022
Counting : 0012
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

int p[N], siz[N], deg[N], sizx[N];

int root(int u){
    if (u == p[u]) return u;
    else return p[u] = root(p[u]);
}

void Union(int u, int v){
    if ((u = root(u)) == (v = root(v))) return;
    if (siz[u] < siz[v]) swap(u, v);
    p[v] = u;
    siz[u] += siz[v];
    sizx[u] += sizx[v];
    deg[u] += deg[v];
}

void solve()
{
    for(int i = 1; i < N; ++i){
        p[i] = i; siz[i] = 1;
        if (i <= MAXA) sizx[i] = 1;
    }
    int n, ans = 0; cin >> n;
    for(int i = 1; i <= n; ++i){
        int x, y; cin >> x >> y;
        y += MAXA;
        deg[root(x)]++; deg[root(y)]++;
        Union(x, y);
    }
    for(int i = 1; i < N; ++i){
        if (p[i] != i) continue;
        if (sizx[i] >= 2 && siz[i] - sizx[i] >= 2){
            ans += sizx[i] * (siz[i] - sizx[i]) - deg[i] / 2;
        }
    }
    cout << ans;
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