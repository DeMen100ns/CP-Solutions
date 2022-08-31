#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N], b[N], n;

bool check(int mid){
    for(int i = 1; i < (n << 1); ++i) b[i] = (a[i] >= mid);
    for(int i = 0; i < n - 1; ++i){
        if (b[n - i] == b[n - i - 1]) return b[n - i];
        if (b[n + i] == b[n + i + 1]) return b[n + i];
    }
    return b[1];
}

void solve()
{
    cin >> n;
    for(int i = 1; i < (n << 1); ++i) cin >> a[i];
    int l = 0, r = 1e9 + 1;
    while (l + 1 < r){
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
