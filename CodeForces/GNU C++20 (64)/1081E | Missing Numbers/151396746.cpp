#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 2e5 + 5;
const int A = 1e4 + 5;
 
int a[N], pref[N];
vector<pair<int, int>> p[N];
 
bool checksqr(int R){
    if (R <= 0)
        return false;
    int sr = sqrt(R);
    return sr * sr == R;
}
 
void solve(){
    int n;
    cin >> n;
    for (int i = 2; i <= n; i += 2){
        cin >> a[i];
        for (int len = 2; len <= 2 * (int)sqrt(a[i]); len += 2){
            int v1 = a[i] % len;
            int v2 = len % 4;
            if ((v1 * 2 == len && v2 == 2) || (v1 + v2 == 0)){
                int d = (a[i] % len > 0);
                p[i].push_back({a[i] / len - len / 4, a[i] / len + len / 4 + d});
            }
        }
        reverse(p[i].begin(), p[i].end());
    }
    for (int i = 2; i <= n; i += 2){
        bool f = false;
        for(auto j : p[i]){
            int l = j.first, r = j.second;
            if (l * l > pref[i - 2]){
                a[i - 1] = l * l - pref[i - 2];
                pref[i - 1] = l * l;
                pref[i] = r * r;
                f = true;
                break;
            }
        }
        if (!f){
            cout << "No";
            return;
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1; // cin >> t;
    while (t--){
        solve();
    }
}