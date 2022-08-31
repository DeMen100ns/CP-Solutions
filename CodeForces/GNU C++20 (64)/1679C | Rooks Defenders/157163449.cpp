/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e6;
const int B = sqrt(N) + 5;
 
int fenr[N], fenc[N], n;
int fr[N], fc[N];
 
void upd(int fen[], int p, int v){
    for(int i = p; i <= n; i += i & -i){
        fen[i] += v;
    }
}
 
int get(int fen[], int p){
    int ans = 0;
    for(int i = p; i; i -= i & -i){
        ans += fen[i];
    }
    return ans;
}
 
int get_range(int fen[], int l, int r){
    return get(fen, r) - get(fen, l - 1);
}
 
bool check(int fen[], int l, int r){
    return get_range(fen, l, r) == r - l + 1;
}
 
void solve()
{
    int q; cin >> n >> q;
    while (q--){
        int type, x1, y1, x2, y2;
        cin >> type >> x1 >> y1;
        if (type == 1){
            if (!fr[x1]) upd(fenr, x1, 1);
            if (!fc[y1]) upd(fenc, y1, 1);
            fr[x1]++; fc[y1]++;
        }
        if (type == 2){
            fr[x1]--; fc[y1]--;
            if (!fr[x1]) upd(fenr, x1, -1);
            if (!fc[y1]) upd(fenc, y1, -1);
        }
        if (type == 3){
            cin >> x2 >> y2;
            if (check(fenr, x1, x2) || check(fenc, y1, y2)) cout << "Yes" << endl;
            else cout << "No" << endl;
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
 
    int t = 1; //cin >> t;
    while (t--)
    {
        solve();
    }
}