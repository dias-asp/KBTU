#include <bits/stdc++.h>
using namespace std;
int p[10000], c[10000], a[1000][1000];
vector < pair < int, pair < int, int > > > edge;

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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        c[i] = 1;
        p[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (i >= j) continue;
            if (a[i][j] == 0) join(i, j);
            else
            {
                edge.push_back({a[i][j], {i, j}});
            }
        }
    }

    sort(edge.begin(), edge.end());

    int ans = 0;
    for (auto cur : edge)
    {
        int w = cur.first;
        int x = cur.second.first;
        int y = cur.second.second;
        if (join(x, y)) ans += w;
    }

    cout << ans;
}
