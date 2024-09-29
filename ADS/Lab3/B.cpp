#include <bits/stdc++.h>
using namespace std;
int a[100500];
int n, m;
bool ch(long long x)
{
    long long sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > x) return 0;
        if (sum + a[i] > x)
        {
            sum = 0;
            cnt++;
        }
        sum += a[i];
    }
    return cnt < m;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long l = 1;
    long long r = 1e14;
    long long ans;
    while (l <= r)
    {
        long long mi = (l + r) / 2;
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
