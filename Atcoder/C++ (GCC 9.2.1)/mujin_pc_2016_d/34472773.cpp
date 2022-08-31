#include <bits/stdc++.h>
using namespace std;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FORR(x,arr) for(auto&& x:arr)
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i,n) for (int i = (n)-1; i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define BIT(n) (1LL<<(n))
#define SZ(x) ((int)(x).size())
typedef long long ll;
// -------------------------------------

template<class V, int N_> class SegTree1 {
  private:
    static constexpr int p2(int n, int m) { return m >= n ? m : p2(n, m * 2); }
    static constexpr int N = p2(N_, 1);
    V comp(V l, V r) { return min(l, r);};
    const V def = std::numeric_limits<V>::max();
  public:
    array<V, N * 2> val;

    SegTree1() {
      reinit();
    }
    void reinit() {
      val.fill(def);
    }
    V getval(int x, int y, int l, int r, int k) {
      if (r <= x || y <= l) return def;
      if (x <= l && r <= y) return val[k];
      return comp(getval(x, y, l, (l + r) / 2, k * 2), getval(x, y, (l + r) / 2, r, k * 2 + 1));
    }
    V getval(int x, int y) {
      return getval(x, y, 0, N, 1);
    }
    void update(int entry, V v) {
      entry += N;
      val[entry] = v;
      while (entry > 1) entry >>= 1, val[entry] = comp(val[entry * 2], val[entry * 2 + 1]);
    }
};
SegTree1<int, 101010> seg1, seg2;

int N, Q;
string S;
int no[101010];
int nc[101010];
int nq[101010];

bool judge(int l, int r) {
  l--;
  if ((r - l) % 2) return false;

  int o = no[r] - no[l];
  int c = nc[r] - nc[l];
  int q = nq[r] - nq[l];

  if (abs(o - c) > q) return false;

  int le = l ? seg1.getval(l, l+1) : 0;
  if (seg1.getval(l+1, r+1) < le) return false;

  int re = seg2.getval(r, r+1);
  if (seg2.getval(l, r) < re) return false;

  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> S >> Q;

  int lv1 = 0, lv2 = 0;
  //seg1.update(0, 0);
  //seg2.update(0, 0);
  REP(i, N) {
    no[i+1] = no[i];
    nc[i+1] = nc[i];
    nq[i+1] = nq[i];
    if (S[i] == '(') {
      seg1.update(i+1, ++lv1);
      seg2.update(i+1, ++lv2);
      no[i+1]++;
    }
    else if (S[i] == ')') {
      seg1.update(i+1, --lv1);
      seg2.update(i+1, --lv2);
      nc[i+1]++;
    }
    else {
      seg1.update(i+1, ++lv1);
      seg2.update(i+1, --lv2);
      nq[i+1]++;
    }
  }

  REP(i, Q) {
    int l, r;
    cin >> l >> r;
    puts(judge(l, r) ? "Yes" : "No");
  }
  return 0;
}
