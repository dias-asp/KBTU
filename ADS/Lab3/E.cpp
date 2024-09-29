#include <bits/stdc++.h>
using namespace std;
int X[200500], Y[200500];
int n, m;
bool ch(int x)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (X[i] <= x && Y[i] <= x) cnt++;
    }
    return cnt >= m;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> X[i] >> Y[i] >> X[i] >> Y[i];
    }
    int l = 1;
    int r = 1e9;
    int ans = 0;
    while (l <= r)
    {
        int mi = (l + r) / 2;
        if (ch(mi))
        {
            r = mi - 1;
            ans = mi;
        }
        else
        {
            l = mi + 1;
        }

    }
    cout << ans;
}
