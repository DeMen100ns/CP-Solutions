#include <bits/stdc++.h>
using namespace std;
#include <atcoder/dsu>

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(auto& [x, y] : a) cin >> x >> y;
    const int S = n, T = n + 1;
    vector<tuple<double, int, int>> edge;
    for(int i = 0; i < n; i++){
        auto [x, y] = a[i];
        edge.emplace_back(y + 100, i, S);
        edge.emplace_back(100 - y, i, T);
    }
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++){
        auto [x1, y1] = a[i];
        auto [x2, y2] = a[j];
        edge.emplace_back(hypot(x1 - x2, y1 - y2), i, j);
    }
    sort(edge.begin(), edge.end());
    atcoder::dsu uf(n + 2);
    for(auto [l, i, j] : edge){
        uf.merge(i, j);
        if(uf.same(S, T)){
            cout << l / 2 << endl;
            return 0;
        }
    }
}
