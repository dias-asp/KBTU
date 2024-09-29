#include <bits/stdc++.h>
using namespace std;
int a[100500];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int k = 1; k <= m; k++)
    {
        int l1, l2, r1, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= l1 && a[i] <= r1 || a[i] >= l2 && a[i] <= r2) cnt++;
        }
        cout << cnt << endl;
    }
}
