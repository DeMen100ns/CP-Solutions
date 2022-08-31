#include <bits/stdc++.h>
 
using namespace std;
 
mt19937 rnd(time(NULL));
 
const int N = 2 * 1000 * 1000 + 11;
const int INF = 1e9;
 
int n;
int a[N][2];
 
vector<int> nums;
int m;
 
vector<int> g[N];
int mt[N];
int used[N];
int T = 1;
 
bool try_kuhn(int v) {
    if (used[v] == T)
        return false;
    used[v] = T;
    
    for (auto to : g[v]) {
        if (mt[to] == -1) {
            mt[to] = v;
            return true;
        }
    }
    
    for (auto to : g[v]) {
        if (try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    
    return false;
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
 
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%d", &a[i][j]);
            nums.push_back(a[i][j]);
        }
    }
    
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    m = nums.size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            a[i][j] = lower_bound(nums.begin(), nums.end(), a[i][j]) - nums.begin();
        }
    }
    
    for (int i = 0; i < n; ++i) {
        g[a[i][0]].push_back(i);
        g[a[i][1]].push_back(i);
    }
 
    memset(mt, -1, sizeof(mt)); 
    int match = 0;
    for (int i = 0; i < m; ++i) {
        if (try_kuhn(i)) {
            ++T;
            ++match;
            if (match == n) {
                printf("%d\n", nums[i]);
                return 0;
            }
        }
    }
    
    puts("-1");
    
    return 0;
}