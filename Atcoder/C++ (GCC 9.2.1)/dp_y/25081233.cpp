#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
long long ans[3005];
pair<long long,long long> a[3005];
long long fact[200005];
long long inv[200005];
long long MOD = 1e9+7;
long long binPow(long long n,long long k)
{
    if(k==0) return 1;
    long long x = binPow(n,k/2)%MOD;
    if(k%2)
    {
        return ((n*x)%MOD)*x%MOD;
    }
    else
    {
        return x*x%MOD;
    }
}
void prep()
{
    fact[0] = fact[1] = 1;
    inv[0] = inv[1] = 1;
    for(long long i = 2; i <= 200000;i++)
    {
        fact[i] = (i*fact[i-1])%MOD;
        inv[i]  = binPow(fact[i],MOD-2);

    }
}
long long C(int n,int k)
{
    return fact[n]*inv[k]%MOD*inv[n-k]%MOD;
}
long long F(int x1,int y1,int x2,int y2)
{
    int v = x2-x1;
    int k = y2-y1;
    return C(v+k,k);
}
void solve()
{
    long long n,m,k;
    cin >> n >> m >> k;
    for(int i = 0; i < k;i++)
        cin >> a[i].first >> a[i].second;
    a[k].first = n;
    a[k].second = m;
    sort(a,a+k+1);
    for(int i = 0; i <= k;i++)
    {
        ans[i] = F(1,1,a[i].first,a[i].second);
        //cout << ans[i] << ' ';
    }
    for (int i=0; i < k;i++)
    for (int j=i+1; j <= k;j++)
    {
         if(a[j].first<a[i].first || a[j].second<a[i].second)  //cell j not affected
            continue;

        //ans[i] stores current number of ways to reach that cell
        //now all paths from cell (1,1) to cell j are blocked
        //so we subtract (number of ways to reach i * number of paths from i to j)
        ans[j] = (ans[j]-ans[i]*F(a[i].first, a[i].second, a[j].first, a[j].second))%MOD;
        if(ans[j] < 0) ans[j] += MOD;
    }
    cout << ans[k];

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    prep();
    solve();
    return 0;
}
    