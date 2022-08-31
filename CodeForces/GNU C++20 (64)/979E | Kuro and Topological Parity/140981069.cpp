#include<bits/stdc++.h>
using namespace std;
const int N = 59, Mod = 1e9 + 7;
int n, p, tot, C[N], Pw[N], dp[N][N][N];
int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
        scanf("%d", &C[i]);
    dp[n + 1][0][0] = Pw[0] = 1;
    for (int i = 1; i < N; i++)
        Pw[i] = (Pw[i - 1] + Pw[i - 1]) % Mod;
    for (int i = n; i; i--)
        for (int b = 0; b <= n - i + 1; b ++)
            for (int w = 0; w + b <= n - i + 1; w ++)
            {
                if (C[i] == -1 || C[i] == 0)
                {
                    if (b)
                        dp[i][b][w] = (dp[i][b][w] + dp[i + 1][b - 1][w] * 1ll * Pw[n - i - (w > 0)]) % Mod;
                    if (w)
                        dp[i][b][w] = (dp[i][b][w] + dp[i + 1][b][w] * 1ll * Pw[n - i - 1]) % Mod;
                }
                if (C[i] == -1 || C[i] == 1)
                {
                    if (w)
                        dp[i][b][w] = (dp[i][b][w] + dp[i + 1][b][w - 1] * 1ll * Pw[n - i - (b > 0)]) % Mod;
                    if (b)
                        dp[i][b][w] = (dp[i][b][w] + dp[i + 1][b][w] * 1ll * Pw[n - i - 1]) % Mod;
                }
            }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if ((i + j) % 2 == p)
                tot = (tot + dp[1][i][j]) % Mod;
    return !printf("%d", tot);
}