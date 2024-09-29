#include <bits/stdc++.h>
using namespace std;
int a[1000500], d[1000500];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = d[i - 1] + a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        int l = 1;
        int r = n;
        int ans = 0;
        while (l <= r)
        {
            int mi = (l + r) / 2;
            if (d[mi] >= x)
            {
                r = mi - 1;
                ans = mi;
            }
            else
            {
                l = mi + 1;
            }
        }
        cout << ans << endl;
    }
}
