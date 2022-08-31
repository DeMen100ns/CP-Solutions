#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstring>
#include <queue>
using namespace std;
int n;
const int maxn = 2e5;
long long a[maxn+5], b[maxn+5], p[maxn+5];
int real[maxn+5];
bool visit[maxn+5];
priority_queue<pair<long long,long long>> q;
vector<pair<int,int>> operation;
bool calc(int x)
{
    bool flag = true;
    for(int i = x; !visit[i]; i = p[i])
    {
       // cout << i << '\n';
        visit[i] = true;
        q.push({-a[i],i});
        flag &= a[i] > b[p[i]];
    }
    if(q.size() == 1) flag = true;
    while(q.size() > 1)
    {
        int x = q.top().second;
        q.pop();
        operation.push_back({x,real[x]});
        real[p[x]] = real[x];
        // 2 3 4 5 1
        // 1 3 4 5 2
        swap(p[x], p[real[x]]);
    }
    q.pop();
    return flag;
}
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 1; i <= n; i++)
        real[p[i]] = i;
    bool flag = true;
    long long ans = n;
    for(int i = 1; i <= n; i++)
    {
        if(!visit[i])
        {
            ans--;
            flag &= calc(i);
        }
        if(!flag)
        {
            cout << -1;
            return;
        }
    }
    cout << ans << '\n';
    for(auto p: operation)
        cout << p.first << ' ' << p.second << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while(t--)
    solve();
}
