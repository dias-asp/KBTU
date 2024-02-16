#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int us[100500], X[100500], Y[100500];
void dfs(int v, int x)
{
    us[v] = 1;
    for (int to = 1; to <= n; to++)
    {
        if (us[to]) continue;
        if (abs(X[v] - X[to]) + abs(Y[v] - Y[to]) <= x) dfs(to, x);
    }
}
bool ch(int x)
{
    for (int i = 1; i <= n; i++) us[i] = 0;
    dfs(1, x);
    return us[n];
}
main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> X[i] >> Y[i];
    }
    int l = 0;
    int r = 2e9;
    int ans = 0;
    while (l <= r)
    {
        int mi = (l + r) / 2;
        if (ch(mi))
        {
            ans = mi;
            r = mi - 1;
        }
        else l = mi + 1;
    }
    cout << ans;
}
