#include <bits/stdc++.h>
using namespace std;
int a[1000500], d[1000500];
int n, m;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int x;
    cin >> x;
    int l = 1;
    int r = n;
    int ans = 0;
    while (l <= r)
    {
        int mi = (l + r) / 2;
        if (a[mi] >= x)
        {
            r = mi - 1;
            ans = mi;
        }
        else l = mi + 1;
    }
    if (a[ans] == x) cout << "Yes";
    else cout << "No";
}
