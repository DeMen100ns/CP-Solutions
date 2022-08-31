#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5e5 + 5;
int a[N];
 
int main()
{
    int n, ans = 0; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1, j = n / 2 + 1; i <= n / 2 && j <= n; ++i, ++j){
     while (j <= n && a[j] < a[i] * 2) ++j;
        if (j > n) break;
        ans++;
    }
    cout << n - ans;
    return 0;
}