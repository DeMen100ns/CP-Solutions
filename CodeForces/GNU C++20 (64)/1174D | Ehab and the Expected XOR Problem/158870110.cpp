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
 
vector <int> pref;
 
void solve()
{
    int n, x; 
 cin >> n >> x;
    pref.push_back(0);
 set <int> s;
    for(int i = 1; i < (1 << n); ++i){
        if (i != x) s.insert(i);
    }
    for(int i = 1; i < (1 << n); ++i){
        if (s.find(i) != s.end()){
            pref.push_back(i);
            s.erase(i); s.erase(i ^ x);
        }
    }
    cout << pref.size() - 1 << endl;
    for(int i = 1; i < pref.size(); ++i){
        cout << (pref[i] ^ pref[i - 1]) << " ";
    }
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