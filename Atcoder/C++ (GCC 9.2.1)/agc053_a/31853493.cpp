#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int INF = 100000;
    int n;
    string s;
    cin >> n >> s;
    vector<int> v(n);
    for(int i = 0; i <= n; i++){
        cin >> v[i];
    }
    int k = INF;
    for(int i = 0; i < n; i++){
        k = min(k,abs(v[i]-v[i+1]));
    }
    vector<vector<int>> ans(k,vector<int>(n+1));
    for(int i = 0; i < k; i++){
        for(int j = 0; j <= n; j++){
            ans[i][j] = v[j]/k;
            if(i < v[j]%k) ans[i][j]++;
        }        
    }
 
    cout << k << endl;
    for(auto i : ans){
        bool b = false;
        for(auto j : i){
            if(b) cout << " ";
            else b = true;
            cout << j;
        }
        cout << endl;
    }
}