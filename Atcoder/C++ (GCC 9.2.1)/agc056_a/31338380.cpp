#include <bits/stdc++.h>

using namespace std;

bool a[1000][1000];

int main(){
	int n; cin >> n;
	for(int i=1;i<=n;i++){
    	a[i][i] = a[i][i + 1] = a[i][i + 3] = 1;
    }
	a[n][2] = a[n][3] = a[n - 1][1] = a[n - 2][1] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
        	if(a[i][j]) cout << '#';
          	else cout << '.';
        } cout << endl;
	}
    return 0;
}