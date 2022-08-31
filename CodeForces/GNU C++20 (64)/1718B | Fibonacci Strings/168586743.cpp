/*
Author : DeMen100ns (a.k.a Vo Khac Trieu)
School : VNU-HCM High school for the Gifted
fuck you adhoc
 
Name:
Sauce: 
Tag: 
Sol: 
Note: 
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;
 
int f[100], a[105], m;
 
multiset <int> s;
 
void solve()
{
    s.clear();
 
    f[0] = 1; f[1] = 1;
    for(int i = 2; i <= 43; ++i){
        f[i] = f[i - 1] + f[i - 2];
    }
    
    int n, sum = 0; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i]; sum += a[i];
        s.insert(a[i]);
    }
 
    int sumf = 0;
    for(int i = 0; i <= 43; ++i){
        sumf += f[i];
        if (sum == sumf){
            m = i;
            break;
        }
 
        if (i == 43){
            cout << "NO" << endl;
            return;
        }
    } m += 0; //trash warning
 
    int last = -1;
    for(int i = m; i >= 0; --i){
        int head = *prev(s.end());
 
        if (head == last){
            if (s.size() == 1){
                cout << "NO" << endl;
                return;
            } else {
                int head = *prev(prev(s.end()));
                s.erase(s.find(head));
                head -= f[i];
                if (head) s.insert(head);
                last = head;
 
                if (head < 0){
                    cout << "NO" << endl;
                    return;
                }
            }
        } else {
            s.erase(s.find(head));
            head -= f[i];
            if (head) s.insert(head);
            last = head;
 
            if (head < 0){
                cout << "NO" << endl;
                return;
            }
        }
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