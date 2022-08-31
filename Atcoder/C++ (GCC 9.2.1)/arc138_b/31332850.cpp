/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

deque <int> d;

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        d.push_back(x);
    }
    int inv = 0;
    while(!d.empty()){
        while(!d.empty() && d.back() == inv) d.pop_back();
        if (d.empty()) break;
        if (d.front() == inv){
            d.pop_front();
            inv ^= 1;
        } else {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
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