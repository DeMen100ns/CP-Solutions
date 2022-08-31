/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

/*
Day start : 09/06/2022
To - day  : 14/06/2022
Counting : 0010
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
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int fact[N];

int C(int n, int k){
    return Div(fact[n], prod(fact[k], fact[n - k]));
}

void solve()
{
    vector <int> v;
	int n, m; cin >> n >> m; fact[0] = 1;
    for(int i = 1; i < N; ++i) fact[i] = prod(fact[i - 1], i);
    int ans = 1;
    for(int i = 2, cur = m; i * i <= cur && m > 1; ++i){
        if (m % i == 0){
            int cnt = 0;
            while (m % i == 0){
                m /= i;
                ++cnt;
            }
            v.push_back(cnt);
        }
    }
    if (m > 1) v.push_back(1);
    for(int i : v){
        mul(ans, C(n + i - 1, n - 1));
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