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

string s;
int cnt[2022];

void solve()
{
    cin >> s;
    int ct = 0, n = s.size(), sum = 0, p = 1;
    cnt[0] = 1;
    for(int i = n - 1; i >= 0; --i){
        sum += (s[i] - '0') * p;
        sum %= 2019;
        ct += cnt[sum];
        cnt[sum]++;
        p = (p * 10) % 2019;
    }
    cout << ct;
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