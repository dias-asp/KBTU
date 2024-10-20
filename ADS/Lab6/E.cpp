#include <bits/stdc++.h>
using namespace std;
int a[2000][2000];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int j = 1; j <= m; j++)
    {
        for (int x = 1; x <= n; x++)
        {
            for (int i = 1; i <= n - 1; i++)
            {
                if (a[i][j] < a[i + 1][j]) swap(a[i][j], a[i + 1][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
