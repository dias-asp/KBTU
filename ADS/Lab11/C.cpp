#include <bits/stdc++.h>
using namespace std;
int p[10000], c[10000];
pair < int, int > edge[10000], b[10000];

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
    int n, m, big, small;
    cin >> n >> m >> big >> small;
    for (int i = 1; i <= m; i++)
    {
        string type;
        cin >> type;
        int x, y, w;
        cin >> x >> y >> w;
        if (type == "small") w *= small;
        if (type == "big") w *= big;
        if (type == "both") w *= min(big, small);
        b[i] = {w, i};
        edge[i] = {x, y};
    }
    for (int i = 1; i <= n; i++)
    {
        c[i] = 1;
        p[i] = i;
    }

    sort(b + 1, b + m +1);
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int w = b[i].first;
        int x = edge[b[i].second].first;
        int y = edge[b[i].second].second;
        if (join(x, y)) ans += w;
    }

    cout << ans;
}
