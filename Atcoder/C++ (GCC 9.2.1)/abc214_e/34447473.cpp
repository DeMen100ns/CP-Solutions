/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/

/*
Name: Packing Under Range Regulations 
Sauce: https://atcoder.jp/contests/abc214/tasks/abc214_e
Tag: Greedy
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

pair<int, int> a[N];
map <int, int> m;

void swapn(pair<int, int> a[], int n){
    for(int i = 1; i <= n; ++i){
        swap(a[i].first, a[i].second);
    }
}

void solve()
{
    m.clear();

    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    swapn(a, n);
    sort(a + 1, a + n + 1);
    swapn(a, n);

    for(int i = 1; i <= n; ++i){
        int l = a[i].first, r = a[i].second;
        int ans;
        while (1){
            if (m.find(l) == m.end()){
                ans = l;
                m[l] = l + 1;
                if (m.find(l + 1) != m.end()){
                    m[l] = m[l + 1];
                }
                break;
            }

            int nxt = m[l];

            if (m.find(nxt) != m.end()){
                m[l] = m[nxt];
            }

            l = nxt;
        }
        if (ans > r){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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