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
 
int a[N];
 
bool checkdiffsetwithoutb(string s, string t){
    string s2, t2;
    for(char c : s){
        if (c != 'b') s2 += c;
    }
    for(char c : t){
        if (c != 'b') t2 += c;
    }
    return (s2 != t2);
}
 
bool checkb(string s, string t){
    int cntas = 0, cntat = 0, cntcs = 0, cntct = 0;
    for(int i = 0; i < (int)s.size(); ++i){
        cntas += (s[i] == 'a');
        cntat += (t[i] == 'a');
        cntcs += (s[s.size() - i - 1] == 'c');
        cntct += (t[s.size() - i - 1] == 'c');
        if (cntas < cntat || cntcs < cntct) return true;
    }
    return false;
}
 
void solve()
{
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if (checkdiffsetwithoutb(s, t)){
        cout << "NO" << endl;
        return;
    }
    if (checkb(s, t)){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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