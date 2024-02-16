
#include <bits/stdc++.h>
using namespace std;
int n, a[1000][1000];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
        if (a[i][i] < 0)
        {
            cout << "YES\n1\n" << i;
            return;
        }
        a[i][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        dist[i] = 1e9;
    }
    dist[1] = 1e9;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i] != 1e9 && dist[i] + a[i][j] < dist[j])
                {
                    if (k == n) e = j;
                    dist[j] = dist[i] + a[i][j];
                    p[j] = i;
                }
            }
        }
    }
}
