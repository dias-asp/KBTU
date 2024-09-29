#include <bits/stdc++.h>
using namespace std;
int a[1000500], d[1000500];
int n, m;
bool ch(int x)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += (a[i] + x - 1) / x;
    }
    return cnt <= m;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1;
    int r = 1000000000;
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
