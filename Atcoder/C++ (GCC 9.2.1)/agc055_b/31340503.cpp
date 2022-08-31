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

string f(string s){
    vector <char> v;
    for(int i = 0; i < s.size(); ++i){
        int k = s[i] - 'A';
        k += 2 * i;
        k %= 3;
        s[i] = 'A' + k;
    }
    for(char c : s){
        int l = v.size();
        if (l >= 2 && v[l - 1] == v[l - 2] && v[l - 1] == c){
            v.pop_back();
            v.pop_back();
        } else {
            v.push_back(c);
        }
    }
    s = "";
    for(char c : v) s += c;
    return s;
}

void solve()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    s = f(s); t = f(t);
    if (s == t){
        cout << "YES";
    } else cout << "NO";
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