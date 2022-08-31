/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

#include <bits/stdc++.h>

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
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

array<int, 4> a[N];
int ans[N], r[N], c[N];

void solve()
{
    int h, w, n; cin >> h >> w >> n;
    for(int i = 1; i <= n; ++i){
        int v, x, y; cin >> x >> y >> v;
        a[i] = {v, x, y, i};
    }
    sort(a + 1, a + n + 1, greater<array<int, 4>>());
    for(int i = 1, j = 1; i <= n; i = j){
        while(j <= n && a[i][0] == a[j][0]) ++j;
        for(int p = i; p < j; ++p){
            ans[a[p][3]] = max(r[a[p][1]], c[a[p][2]]);
        }
        for(int p = i; p < j; ++p){
            r[a[p][1]] = max(r[a[p][1]], ans[a[p][3]] + 1);
            c[a[p][2]] = max(c[a[p][2]], ans[a[p][3]] + 1);
        }
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << endl;
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