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

int a[N];
char c[N];
vector <int> basis;

void ins(int v){
	for(int i : basis){
		v = min(v, v ^ i);
	}
	if (v) basis.push_back(v);
}

bool find(int v){
	for(int i : basis){
		v = min(v, v ^ i);
	}
	return (v == 0);
}

void solve(){
    basis.clear();
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
    	cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
    	cin >> c[i];
    }
    for(int i = n; i; --i){
    	if (c[i] == '0'){
    		ins(a[i]);
    	} else {
    		if (!find(a[i])){
    			cout << 1 << endl;
    			return;
    		}
    	}
    }
    cout << 0 << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    //freopen("codeforces.inp","r",stdin);
    //freopen("codeforces.out","w",stdout);
    
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

//
