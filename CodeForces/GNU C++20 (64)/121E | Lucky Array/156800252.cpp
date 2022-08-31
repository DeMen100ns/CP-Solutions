/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
/*
Note : 
R[i] = i * B
block[id] = (id - 1) / B + 1 
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e4 + 5;
const int B = sqrt(N * 30) + 5;
const int B2 = N / B + 5;
 
const int lucky[30] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777};
 
int a[N], sum[B], cnt[B][MAXA];
int block[N], L[B], R[B];
 
bool neardis(int val){
    if (val > 7777) return false;
    int k = *lower_bound(lucky, lucky + 30, val);
    return (k == val);
}
 
void upd(int l, int r, int v){
    int bl = block[l], br = block[r];
    if (bl == br){
        int b = bl;
        for(int i = l; i <= r; ++i){
            cnt[b][a[i]]--;
            a[i] += v;
            cnt[b][a[i]]++;
        }
        return;
    }
    if (l != L[bl]){
        int b = bl;
        for(int i = l; i <= R[bl]; ++i){
            cnt[b][a[i]]--;
            a[i] += v;
            cnt[b][a[i]]++;
        }
        ++bl;
    }
    if (r != R[br]){
        int b = br;
        for(int i = L[br]; i <= r; ++i){
            cnt[b][a[i]]--;
            a[i] += v;
            cnt[b][a[i]]++;
        }
        --br;
    }
    for(int i = bl; i <= br; ++i){
        sum[i] += v;
    }
}
 
int get(int l, int r){
    int ans = 0;
    int bl = block[l], br = block[r];
    if (bl == br){
        int b = bl;
        for(int i = l; i <= r; ++i){
            ans += neardis(a[i] + sum[b]);
        }
        return ans;
    }
    if (l != L[bl]){
        int b = bl;
        for(int i = l; i <= R[bl]; ++i){
            ans += neardis(a[i] + sum[b]);
        }
        ++bl;
    }
    if (r != R[br]){
        int b = br;
        for(int i = L[br]; i <= r; ++i){
            ans += neardis(a[i] + sum[b]);
        }
        --br;
    }
    for(int i = bl; i <= br; ++i){
        for(int p = 0; p < 30; ++p){
            if (lucky[p] <= sum[i]) continue;
            ans += cnt[i][lucky[p] - sum[i]];
        }
    }
    return ans;
}
 
void solve()
{
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        block[i] = (i - 1) / B + 1;
        cnt[block[i]][a[i]]++;
    }
    
    for(int i = 1; i <= block[n]; ++i){
        R[i] = i * B; L[i] = R[i] - B + 1;
        R[i] = min(R[i], n);
    }
    while(q--){
        string type;
        int l, r, d;
        cin >> type >> l >> r;
        if (type == "add"){
            cin >> d;
            upd(l, r, d);
        } else {
            cout << get(l, r) << endl;
        }
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