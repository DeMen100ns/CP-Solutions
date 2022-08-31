#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[3001][3001];
ll a[3001];

int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        dp[i][i]=a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=i-1;j>=1;j--){
            dp[j][i]=max(a[j]-dp[j+1][i], a[i]-dp[j][i-1]);
        }
    }
    cout << dp[1][n];
}