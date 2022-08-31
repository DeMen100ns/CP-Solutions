#include <bits/stdc++.h>
using namespace std;
 
long long n, a[100003], b[100003], h, ans = 0;
 
bool solve(int mid){
    for(int i = 1; i <= mid; ++i) b[i] = a[i];
    sort(b + 1, b + mid + 1);
 
    long long tmp = 0, tmp2 = 0;
 
    for (int i = 1; i <= mid; i++){
        if (i & 1) tmp += b[i];
        else tmp2 += b[i];
    }
    // cout << mid << ' ' << tmp << '\n';
 
    return (max(tmp, tmp2) <= h);
}
 
int main(){
 
    cin >> n >> h;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
 
    int l = 0, r = n + 1;
    while (l + 1 < r){
        int mid = (l + r) >> 1;
        if (solve(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}