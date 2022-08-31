/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
 
//#define int long long
#define dbg(a) cerr << #a << " : " << a << endl;
#define dbgc(a) cerr << #a << " : "; for(auto i : a) cerr << i << " "; cerr << endl
#define dbgarr(a, l, r) cerr << #a << " : "; for(long long i = l; i <= r; ++i) cerr << a[i] << " "; cerr << endl
 
using namespace std;
 
const int N = 2e5 + 5;
const int logn = 20;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
const int MOD = 1e9 + 7;
 
using ii = pair<int, int>;
#define x first
#define y second
 
int trie[30 * N][2], ct[30 * 2 * N], cnt = 0;
 
void ins(int v){
    int u = 0;
    for(int i = 29; i >= 0; --i){
        int p = v >> i & 1;
        if (!trie[u][p]){
            trie[u][p] = ++cnt;
        }
        ct[trie[u][p]]++;
        u = trie[u][p];
    }
}
 
void del(int v){
    int u = 0;
    for(int i = 29; i >= 0; --i){
        int p = v >> i & 1;
        ct[trie[u][p]]--;
        u = trie[u][p];
    }
}
 
int get(int v){
    int u = 0, ans = 0;
    for(int i = 29; i >= 0; --i){
        int p = v >> i & 1;
        if (ct[trie[u][p ^ 1]]){
            ans |= 1 << i;
            u = trie[u][p ^ 1];
        } else u = trie[u][p];
    }
    return ans;
}
 
void solve(){
    int q; cin >> q;
    ins(0);
    while (q--){
        char type; int v;
        cin >> type >> v;
        if (type == '+') ins(v);
        if (type == '-') del(v);
        if (type == '?')
            cout << get(v) << endl;
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    //freopen("codeforces.inp","r",stdin);
    //freopen("codeforces.out","w",stdout);
 
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
}