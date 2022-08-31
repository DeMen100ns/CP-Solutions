/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/
 
#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int N = 3e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], fen1[N], fen2[N];
int n;
 
int get(int p){
    int ans1 = 0, ans2 = 0;
    for(int i = p; i; i -= i & -i){
        ans1 += fen1[i];
        ans2 += fen2[i];
    }
    return ans1 * p + ans2;
}
 
void upd(int fen[], int p, int v){
    for(int i = p; i <= n; i += i & -i){
        fen[i] += v;
    }
}
 
void upd_range(int fen[], int l, int r, int v){
    upd(fen, l, v);
    upd(fen, r + 1, -v);
}
 
void solve()
{
    int k, cnt = 0; cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = n; i >= k; --i){
        int v = get(i);
        int tme = max((int)0, (a[i] - v + k - 1) / k);
        upd_range(fen1, i - k + 1, i, tme);
        upd_range(fen2, i - k + 1, i, -tme * (i - k));
        cnt += tme;
    }
    int add = 0;
    for(int i = k - 1; i; --i){
        add = max(add, (a[i] - get(i) + i - 1) / i);
    }
    cout << cnt + add;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1; // cin >> t;
    while (t--)
    {
        solve();
    }
}