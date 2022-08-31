#include <bits/stdc++.h>

using namespace std;

double sol[3000][3000];

int main(){
    int n;
    double k;
    cin >> n;
    sol[0][0]=1;
    for (int i=1;i<=n;i++){
        cin >> k;
        for (int j=0;j<=i;j++){
            sol[i][j]=sol[i-1][j-1]*k+sol[i-1][j]*(1-k);
        }
    }
    double t;
    for (int i=n/2+1;i<=n;i++){
        t+=sol[n][i];
    }
    cout << setprecision(10) << fixed << t;
}