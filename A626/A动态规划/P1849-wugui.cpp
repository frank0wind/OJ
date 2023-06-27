#include <bits/stdc++.h>
using namespace std;
int n, m, a[351], r[5], dp[41][41][41][41];
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
inline int read()
{
    char c = getchar();
    int x = 0;
    bool f = 0;
    for (; !isdigit(c); c = getchar())
        f ^= !(c ^ 45);
    for (; isdigit(c); c = getchar())
        x = (x << 1) + (x << 3) + (c ^ 48);
    if (f)
        x = -x;
    return x;
}
int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for (int i = 1; i <= m; i++)
    {
        int b;
        b = read();
        r[b]++;
    }
    dp[0][0][0][0] = a[1];
    for (register int r1 = 0; r1 <= r[1]; r1++)
        for (register int r2 = 0; r2 <= r[2]; r2++)
            for (register int r3 = 0; r3 <= r[3]; r3++)
                for (register int r4 = 0; r4 <= r[4]; r4++)
                {
                    int j = 1 + r1 * 1 + r2 * 2 + r3 * 3 + r4 * 4;
                    int mmax = 0;
                    if (r1 != 0)
                        mmax = max(mmax, dp[r1 - 1][r2][r3][r4] + a[j]);
                    if (r2 != 0)
                        mmax = max(mmax, dp[r1][r2 - 1][r3][r4] + a[j]);
                    if (r3 != 0)
                        mmax = max(mmax, dp[r1][r2][r3 - 1][r4] + a[j]);
                    if (r4 != 0)
                        mmax = max(mmax, dp[r1][r2][r3][r4 - 1] + a[j]);
                    dp[r1][r2][r3][r4] = max(dp[r1][r2][r3][r4], mmax);
                }
    cout << dp[r[1]][r[2]][r[3]][r[4]];
    return 0;
}