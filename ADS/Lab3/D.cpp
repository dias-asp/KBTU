#include <bits/stdc++.h>
using namespace std;
int a[100500];
int n, m;

int calc(int x)
{
    int l = 1;
    int r = n;
    int ans = 0;
    while (l <= r)
    {
        int mi = (l + r) / 2;
        if (a[mi] <= x)
        {
            ans = mi;
            l = mi + 1;
        }
        else
        {
            r = mi - 1;
        }
    }
    return ans;
}
int calc(int l, int r)
{
    return calc(r) - calc(l - 1);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int k = 1; k <= m; k++)
    {
        int l1, l2, r1, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if (r1 > r2)
        {
            swap(l1, l2);
            swap(r1, r2);
        }

        int cnt = calc(l1, r1) + calc(l2, r2);
        if (l1 >= l2 && r1 <= r2) cnt -= calc(l1, r1);
        else if (r1 >= l2) cnt -= calc(l2, r1);

        cout << cnt << endl;
    }
}
