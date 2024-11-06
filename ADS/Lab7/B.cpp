#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector < int > a, b, c;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    int l = 0, r = 0;
    while (l < n && r < m)
    {
        if (a[l] < b[r]) c.push_back(a[l++]);
        else c.push_back(b[r++]);
    }
    while (l < n) c.push_back(a[l++]);
    while (r < m) c.push_back(b[r++]);
    for (auto i : c) cout << i << " ";
}
