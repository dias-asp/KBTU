#include <bits/stdc++.h>
using namespace std;
int a[1000500], d[1000500];
int n, m;
bool ch(int x)
{
    int sum = 0;
    for (int i = 1; i <= x; i++) sum += a[i];
    if (sum >= m) return 1;
    for (int i = x + 1; i <= n; i++)
    {
        sum += a[i];
        sum -= a[i - x];
        if (sum >= m) return 1;
    }
    return 0;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1;
    int r = n;
    int ans = 0;
    while (l <= r)
    {
        int mi = (l + r) / 2;
        if (ch(mi))
        {
            r = mi - 1;
            ans = mi;
        }
        else l = mi + 1;
    }
    cout << ans;
}
