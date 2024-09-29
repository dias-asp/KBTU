#include <bits/stdc++.h>
using namespace std;
int b[100000], a[1000][1000];
int main()
{
    int w, n, m;
    cin >> w;
    for (int i = 1; i <= w; i++)
    {
        cin >> b[i];
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= w; i++)
    {
        int line = 0;
        for (int j = 1; j <= n; j++)
        {
            if (b[i] >= min(a[j][1], a[j][m]) && b[i] <= max(a[j][1], a[j][m])) line = j;
        }
        bool found = 0;
        for (int j = 1; j <= m; j++)
        {
            if (a[line][j] == b[i])
            {
                found = 1;
                cout << line - 1 << " " << j - 1 << endl;
            }
        }
        if (!found) cout << "-1\n";
    }
}
