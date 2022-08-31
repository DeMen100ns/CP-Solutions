#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(x, y, z) for (int x = y; x <= z; x++)
#define dep(x, y, z) for (int x = y; x >= z; x--)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof a) // others
#define endl '\n'

typedef unsigned long long ull;
typedef pair<int, int> pii;

template<class T> void minn(T& a, T b) {if (a > b) a = b;}
template<class T> void maxx(T& a, T b) {if (a < b) a = b;}

const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n;
int lg[N];
void ini() {
    for (int i = 2; i <= N - 1; i++) lg[i]  = lg[i >> 1] + 1;
}

struct ST {
    vector<vector<int>> st;
    int n;
    ST(vector<int> a) {
        n = sz(a);
        st.resize(n + 1);
        for (auto& x : st) x.resize(23);
        rep (i, 1, n) {
            st[i][0] = a[i - 1];
        }
        for (int j = 1; j <= 22; j++) {
            for (int i = 1; (i + (1 << j) - 1) <= n; i++) {
                st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int get(int l, int r) {
        int s = lg[r - l + 1];
        return gcd(st[l][s], st[r - (1 << s) + 1][s]);
    }
};


void solve() {
    int q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int h1, h2, w1, w2;
    vector<int> c(a);
    vector<int> d(b);
    rep (i, 1, n - 1) {
        c[i] = a[i] - a[i - 1];
    }
    rep (i, 1, n - 1) {
        d[i] = b[i] - b[i - 1];
    }
    ST r(c), cl(d);
    while (q--) {
        cin >> h1 >> h2 >> w1 >> w2;
        int g = a[h1 - 1] + b[w1 - 1];
        if (w1 < w2)
        g = gcd(g, cl.get(w1 + 1, w2));
        if (h1 < h2)
        g = gcd(g, r.get(h1 + 1, h2));
      assert(g>=0);
        cout << g << endl;
    }

}
signed main()
{
    ini();
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    for (int i = 1; i <= T; i++) {
        solve();
    }
}




