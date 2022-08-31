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

int d[N], dp[N], ans[N], cnt = 1;
vector <int> a[N];
pair<int, int> ma = {0, 0};

void dfs(int u, int par = 0){
    ma = max(ma, {d[u], u});
    dp[u] = 0;
    for(int i : a[u]){
        if (i == par) continue;
        d[i] = d[u] + 1;
        dfs(i, u);
        dp[u] = max(dp[u], dp[i]);
    }
    ++dp[u];
}

bool cmp(int u, int v){
    return dp[u] < dp[v];
}

void dfs_ans(int u, int par = 0){
    ans[u] = cnt;
    sort(a[u].begin(), a[u].end(), cmp);
    for(int i : a[u]){
        if (i == par) continue;
        ++cnt;
        dfs_ans(i, u);
        ++cnt;
    }
}

void solve()
{
    int n; cin >> n;
    for(int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1); int h = ma.second;
    dfs(h); dfs_ans(h);
    for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
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