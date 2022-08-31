/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
/*
Sauce : https://codeforces.com/contest/484/problem/E
 
Tag : Segment tree (Merge node), Parallel BS
 
Solution : -
 
Note : -
 
Complexity : O(q * log(n) * log(h))
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
template<typename T> int SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> int SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, int x1=0, int x2=1e9){ string ret = ""; for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), int x1, int x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<int Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
 
const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
struct node{
 int pre, suf, ans, l, r;
} seg[4 * N];
 
int a[N], oldv[N];
int l[N], r[N], w[N];
int L[N], R[N];
vector <int> v, Q[N], pos[N];
 
node merge(node nodel, node noder){
 if (nodel.ans == -1) return noder;
 if (noder.ans == -1) return nodel;
 node res;
 res.l = nodel.l;
 res.r = noder.r;
 if (nodel.pre == nodel.r - nodel.l + 1){
  res.pre = nodel.pre + noder.pre;
 } else res.pre = nodel.pre;
 if (noder.suf == noder.r - noder.l + 1){
  res.suf = nodel.suf + noder.suf;
 } else res.suf = noder.suf;
 res.ans = max({nodel.ans, noder.ans, nodel.suf + noder.pre, res.pre, res.suf});
 return res;
}
 
void upd(int id, int l, int r, int pos, int val){
 if (l == r && r == pos){
  seg[id].pre = seg[id].suf = seg[id].ans = 1;
  seg[id].l = seg[id].r = l;
  return;
 }
 int mid = (l + r) >> 1;
 if (mid >= pos) upd(id << 1, l, mid, pos, val);
 else upd(id << 1 | 1, mid + 1, r, pos, val);
 seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}
 
node get(int id, int l, int r, int u, int v){
 if (l > v || r < u) return {-1, -1, -1, -1, -1};
 if (l >= u && r <= v){
  return seg[id];
 }
 int mid = (l + r) >> 1;
 node n1 = get(id << 1, l, mid, u, v);
 node n2 = get(id << 1 | 1, mid + 1, r, u, v);
 return merge(n1, n2);
}
 
void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
     cin >> a[i];
     v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(int i = 1; i <= n; ++i){
     int h = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
     oldv[h] = a[i];
     a[i] = h;
     pos[h].push_back(i);
    }
    int q; cin >> q;
    for(int i = 1; i <= q; ++i){
     cin >> l[i] >> r[i] >> w[i];
     L[i] = 0; R[i] = v.size() + 1;
    }
    bool change = true;
    while (change){
     change = false;
     //dbg(change);
     memset(seg, 0, sizeof seg);
     for(int i = 1; i <= q; ++i){
      if (L[i] + 1 < R[i]){
       Q[(L[i] + R[i]) >> 1].push_back(i);
      }
     }
     //dbg(Q, 1, v.size());
     for(int i = v.size(); i > 0; --i){
      for(int p : pos[i]){
       upd(1, 1, n, p, 1);
      }
      for(int id : Q[i]){
       change = true;
       int k = get(1, 1, n, l[id], r[id]).ans;
       if (k >= w[id]){
        L[id] = i;
       } else R[id] = i;
      }
      Q[i].clear();
     }
     //dbg(L, 1, q);
     //dbg(R, 1, q);
    }
    for(int i = 1; i <= q; ++i){
     cout << oldv[L[i]] << endl;
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