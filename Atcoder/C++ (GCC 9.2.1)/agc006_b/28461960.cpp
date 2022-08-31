#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    if (x == 1 || x == 2 * n - 1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        for (int i = 0; i < 2 * n - 1; i++)
        {
            cout << (i + x - n + (2 * n - 1)) % (2 * n - 1) + 1 << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
