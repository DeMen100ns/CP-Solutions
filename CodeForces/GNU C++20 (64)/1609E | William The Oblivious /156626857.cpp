/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[4 * N], b[4 * N], c[4 * N], ab[4 * N], bc[4 * N], abc[4 * N];
 
void merge(int id){
    a[id] = a[id << 1] + a[id << 1 | 1];
    b[id] = b[id << 1] + b[id << 1 | 1];
    c[id] = c[id << 1] + c[id << 1 | 1];
    ab[id] = min(a[id << 1] + ab[id << 1 | 1], ab[id << 1] + b[id << 1 | 1]);
    bc[id] = min(b[id << 1] + bc[id << 1 | 1], bc[id << 1] + c[id << 1 | 1]);
    abc[id] = min({a[id << 1] + abc[id << 1 | 1], ab[id << 1] + bc[id << 1 | 1], abc[id << 1] + c[id << 1 | 1]});
}
 
void upd(int id, int l, int r, int pos, char ch){
    if (l == r){
        a[id] = (ch == 'a');
        b[id] = (ch == 'b');
        c[id] = (ch == 'c');
        ab[id] = bc[id] = abc[id] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) upd(id << 1, l, mid, pos, ch);
    else upd(id << 1 | 1, mid + 1, r, pos, ch);
 
    merge(id);
}
 
void solve()
{
    int n, q; cin >> n >> q;
    string s; cin >> s; s = " " + s;
    for(int i = 1; i <= n; ++i){
        upd(1, 1, n, i, s[i]);
    }
    while (q--){
        int p; char c;
        cin >> p >> c;
        upd(1, 1, n, p, c);
        cout << abc[1] << endl;
    }
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