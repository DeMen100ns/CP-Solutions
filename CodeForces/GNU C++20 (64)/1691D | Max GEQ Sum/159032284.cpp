/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
struct segtree{
    int seg[4 * N], lazy[4 * N];
 
    void down(int id){
        int t = lazy[id];
        seg[id << 1] += t; seg[id << 1 | 1] += t;
        lazy[id << 1] += t; lazy[id << 1 | 1] += t;
        lazy[id] = 0;
    }
 
    void upd(int id, int l, int r, int u, int val){
        if (r < u) return;
        if (l >= u){
            seg[id] += val;
            lazy[id] += val;
            return;
        }
        down(id);
        int mid = (l + r) >> 1;
        upd(id << 1, l, mid, u, val);
        upd(id << 1 | 1, mid + 1, r, u, val);
        seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
    }
 
    int get(int id, int l, int r, int u, int v){
        if (l > v || r < u) return -INF;
        if (l >= u && r <= v){
            return seg[id];
        }
        down(id);
        int mid = (l + r) >> 1;
        int v1 = get(id << 1, l, mid, u, v);
        int v2 = get(id << 1 | 1, mid + 1, r, u, v);
        return max(v1, v2);
    }
 
    void build(int a[], int id, int l, int r){
        if (l == r){
            seg[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(a, id << 1, l, mid);
        build(a, id << 1 | 1, mid + 1, r);
        seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
    }
} segp, segs;
 
int a[N], pre[N], suf[N], l[N], r[N];
 
void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    suf[n + 1] = 0;
    for(int i = n; i; --i){
        suf[i] = suf[i + 1] + a[i];
    }
    segp.build(pre, 1, 1, n);
    segs.build(suf, 1, 1, n);
 
    for (int i = 1; i <= n; i++) {
        l[i] = i;
        while (l[i] > 1 && a[i] >= a[l[i]-1])
            l[i] = l[l[i]-1];
    }
    for (int i = n; i >= 1; i--) {
        r[i] = i;
        while (r[i] < n && a[i] >= a[r[i]+1])
            r[i] = r[r[i]+1];
    }
 
    for(int i = 1; i <= n; ++i){
        int mi = 0;
        mi = max(segs.get(1, 1, n, l[i], i - 1) - suf[i], segp.get(1, 1, n, i + 1, r[i]) - pre[i]);
        if (mi > 0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1; cin >> t;
    while (t--)
    {
        solve();
    }
}