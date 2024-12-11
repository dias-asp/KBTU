#include <bits/stdc++.h>
using namespace std;
int n, a[1000][1000], b[1000], us[1000];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    for (int k = 1; k <= n; k++)
    {
        us[b[k]] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                a[i][j] = min(a[i][j], a[i][b[k]] + a[b[k]][j]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (us[i] && us[j]) ans = max(ans, a[i][j]);
            }
        }
        cout << ans << endl;
    }
}
