/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18 + 7;
const int MAXA = 1e9;
const int B = sqrt(N) + 5;

int rnk = 0;
vector <int> basis;

int a[N];

void ins(int a){
	for(int i : basis){
		a = min(a, a ^ i);
	}
    if (a) basis.push_back(a);
}

int msb(int i){
    i |= (i >> 1);
    i |= (i >> 2);
    i |= (i >> 4);
    i |= (i >> 8);
    i |= (i >> 16);
    i |= (i >> 32);
    return (i + 1) >> 1;
}

void solve(){
    int n, ans = 0, xorsum = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
    	cin >> a[i];
        xorsum ^= a[i];
    } 
    for(int i = 1; i <= n; ++i){
        ins(a[i] & (~xorsum));
    } 
    //max(x + sum ^ x);
    for(int i : basis){
        if (xorsum & msb(i)) continue;
        ans = max(ans, ans ^ i);
    }
    cout << ans + (xorsum ^ ans);
}

signed main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    //freopen("codeforces.inp","r",stdin);
    //freopen("codeforces.out","w",stdout);
    
    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
}