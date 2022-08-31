/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int r1[N], r2[N];
 
bool f(int k, string &s){
    //cout << s << " " << k << endl;
    int n = s.size() - 1;
    int j1 = 1, j2 = 1, cnt1 = 0, cnt2 = 0;
    for(char c : s){
        cnt2 += (c == '1');
    }
    for(int i = 1; i <= n; ++i){
        while(j1 <= n && cnt1 <= k){
            cnt1 += (s[j1] == '0');
            ++j1;
        }
        //r1[i] = j1 - 1;
        while(j2 <= n && cnt2 > k){
            cnt2 -= (s[j2] == '1');
            ++j2;
        }
        //r2[i] = j2 - 1;
        //cout << j1 - 2 << " " << j2 - 1 << endl;
        if (j1 >= j2 && cnt2 <= k) return true;
        cnt1 -= (s[i] == '0');
        cnt2 += (s[i] == '1');
    }
    return false;
}
 
void solve()
{
    string s; cin >> s;
    s = " " + s;
    int l = -1, r = s.size() - 1;
    while (l + 1 < r){
        int mid = (l + r) >> 1;
        if (f(mid, s)) r = mid;
        else l = mid;
    }
    cout << r << endl;
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