/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
fuck you spy
*/
 
#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e7 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 2e7;
const int B = sqrt(N) + 5;
 
int u[N];
int c, d, x;
 
void precal(){
    fill(u + 1, u + MAXA + 1, 1);
    for(int i = 2; i <= MAXA; ++i){
        if (u[i] != 1) continue;
        for(int j = 1; i * j <= MAXA; j++)
            u[i * j] <<= 1;
    }
}
 
int cal(int g){
    int lcm = d * g + x;
    if (lcm % c) return 0;
    lcm /= c;
    if (lcm % g) return 0;
    int p = lcm / g;
    //cout << lcm << " " << g << " " << p << " " << u[p] << endl;
    return u[p];
}
 
void solve()
{
    cin >> c >> d >> x;
    //c * lcm(a, b) - d * gcd(a, b) = x
    long long ans = 0;
    for(int g = 1; g * g <= x; ++g){
        if (x % g) continue;
        ans += cal(g);
        if (x / g != g) ans += cal(x / g);
    }
    cout << ans << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("codeforces.inp","r",stdin);
    // freopen("codeforces.out","w",stdout);
 
    int t = 1; cin >> t;
    precal();
    while (t--)
    {
        solve();
    }
}