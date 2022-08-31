/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int a[N], cnt[N];
vector <int> v, v2;
 
void solve()
{
    v.clear(); v2.clear();
    int n, cnt0 = 0; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i < n; ++i){
        if (a[i + 1] > a[i]) v.push_back(a[i + 1] - a[i]);
        else cnt0++;
    }
 
    sort(v.begin(), v.end());
 
    for(int i = 1; i <= n - 2; ++i){
        if (v.empty()){
            cout << 0 << endl;
            return;
        }
        if (cnt0) {
            v2.push_back(v[0]);
            --cnt0;
        }
        for(int j = 0; j < (int)v.size() - 1; ++j){
            if (v[j + 1] > v[j]) v2.push_back(v[j + 1] - v[j]);
            else cnt0++;
        }
        sort(v2.begin(), v2.end());
        swap(v, v2);
        v2.clear();
    }
    if (!v.empty()) cout << v[0] << endl;
    else cout << 0 << endl;
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