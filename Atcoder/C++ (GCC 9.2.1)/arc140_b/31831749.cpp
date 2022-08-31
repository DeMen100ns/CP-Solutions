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
 
int l[N], r[N];
 
void solve()
{
    multiset <int> v;
    int n; cin >> n;
    string s; cin >> s;
    int A = 0, C = 0;
    bool f = false;
    for(int i = 0; i < n; ++i){
        char c = s[i];
        if (c == 'A'){
            if (!f) ++A;
            else{
                A = 1; f = false;
            }
        }
        if (c == 'R'){
            if (!f && A) f = true;
            else {
                f = false;
                A = 0;
            }
        }
        if (c == 'C'){
            if (!f){
                A = C = 0;
            } else {
                ++C;
                if (i == n - 1 || s[i + 1] != 'C'){
                    v.insert(min(A, C));
                    A = C = 0;
                    f = false;
                }
            }
        }
    }
    int cnt = 0;
    while (!v.empty()){
        if (!(cnt & 1)){
            auto it = v.upper_bound(1);
            if (it == v.end()){
                it = v.begin();
                v.erase(it);
            } else {
                v.insert((*it) - 1);
                v.erase(it);
            }
        } else {
            auto it = v.begin();
            v.erase(it);
        }
        ++cnt;
    }
    cout << cnt;
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