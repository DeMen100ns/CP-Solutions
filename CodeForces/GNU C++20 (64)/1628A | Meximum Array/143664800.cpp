/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/
 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
long long a[maxn+5];
vector<int> pos[maxn+5];
long long n;
int cnt[maxn+5];
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i], pos[a[i]].push_back(i);
    int current = 0;
    vector<int> ans;
    int old = 1;
  //  long long maxx = 0;
    int earliest = 1;
    for(int i = 1; i <= n; i++)
    {
        cnt[a[i]]++;
        while(cnt[current]) current++, earliest = i;
        if((lower_bound(pos[current].begin(),pos[current].end(),i+1) == pos[current].end()))
        {
            ans.push_back(current);
            for(int k = old; k <= i; k++)
                cnt[a[k]]--;
            current = 0;
            old = i+1;
        }
    }
    for(int i = 0; i <= n; i++)
        cnt[i] = 0;
    for(int i = 0; i <= n; i++)
            pos[i].clear();
    if(old != n+1)
    {
        ans.push_back(current);
    //    cout << current << ' ' << earliest << '\n';
        for(int i = earliest+1; i <= n; i++)
            ans.push_back(0);
    }
    cout << ans.size() << '\n';
    for(auto x: ans)
        cout << x << ' ';
    cout << '\n';
 
 
 
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    solve();
    return 0;
}