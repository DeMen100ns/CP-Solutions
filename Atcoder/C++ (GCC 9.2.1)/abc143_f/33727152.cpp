/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc

Name: Distinct Numbers
Sauce: https://atcoder.jp/contests/abc143/tasks/abc143_f
Tag: Math, Greedy
Sol: 
- cnt : counting array of a
- ccnt : counting array of cnt
- f(X) : Maximum length when partition array a to X arrays.
- f(X) = sigma(min(cnt[i], X)) / X = sigma(min(i, X) * ccnt[i]) / X

Note: 
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long INF = numeric_limits<long long>::max() / 2;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int a[N], cnt[N], ccnt[N], f[N], ans[N];

void solve()
{
    int n, sum1 = 0, sum2 = 0; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if (cnt[a[i]]) ccnt[cnt[a[i]]]--;
        cnt[a[i]]++;
        ccnt[cnt[a[i]]]++;

        sum2 += (cnt[a[i]] == 1);
    }

    for(int i = 1; i <= n; ++i){
        sum1 += i * ccnt[i];
        sum2 -= ccnt[i];
        f[i] = (sum1 + i * sum2) / i;
        ans[f[i]] = i;
    }
    for(int i = n - 1; i; --i){
        if (ans[i]) continue;
        ans[i] = ans[i + 1];
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << endl;
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