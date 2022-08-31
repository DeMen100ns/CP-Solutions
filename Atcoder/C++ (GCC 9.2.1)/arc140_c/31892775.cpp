#include <bits/stdc++.h>
using namespace std;
 
vector<int> repeated(const vector<int> &D)
{
    int N = D.size();
    int at = (N - 1) / 2, bat = (N - 1) / 2 + 1;
    vector<int> res;
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            res.push_back(D[at]);
            at--;
        }
        else
        {
            res.push_back(D[bat]);
            bat++;
        }
    }
    return res;
}
 
int main()
{
    int N, X;
    cin >> N >> X;
    X--;
    if (N % 2 == 0 && X == N / 2 - 1)
    {
        vector<int> idx;
        for (int i = 0; i < N; i++)
            idx.push_back(i);
        vector<int> res = repeated(idx);
        for (int i = 0; i < N; i++)
        {
            cout << res[i] + 1 << " ";
        }
        cout << endl;
    }
    else
    {
        vector<int> idx;
        for (int i = 0; i < N; i++)
        {
            if (X != i)
                idx.push_back(i);
        }
        vector<int> res = repeated(idx);
        res.insert(res.begin(), X);
        for (int i = 0; i < N; i++)
        {
            cout << res[i] + 1 << " ";
        }
        cout << endl;
    }
}