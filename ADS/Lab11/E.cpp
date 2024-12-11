#include <bits/stdc++.h>
using namespace std;
int p[200500], c[200500];
vector < int > g[200500];

int pr(int x)
{
    if (p[x] == x) return x;
    return p[x] = pr(p[x]);
}
bool join(int x, int y)
{
    x = pr(x);
    y = pr(y);
    if (x == y) return 0;
    if (c[x] > c[y]) swap(x, y); //x < y
    c[y] += c[x];
    p[x] = y;
    return 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y > x) g[x].push_back(y);
        if (x > y) g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        c[i] = 1;
        p[i] = i;
    }

    vector < int > ans;
    ans.push_back(0);
    int cnt = 0;
    for (int i = n; i > 1; i--)
    {
        cnt++;
        for (auto to : g[i])
        {
            if (join(i, to)) cnt--;
        }
        ans.push_back(cnt);
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x << endl;
}
