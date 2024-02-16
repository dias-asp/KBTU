#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, cost;
};

int n, m, a[1000][1000];
vector<Edge> edges;
const int INF = 1000000000;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            Edge e;
            e.a = i;
            e.b = j;
            e.cost = a[i][j];
            edges.push_back(e);
        }
    }
    vector<int> d(n, INF);
    vector<int> p(n, -1);
    int x;

    d[0] = 0;

    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] < INF && d[e.a] + e.cost < d[e.b]) {
                d[e.b] = max(-INF, d[e.a] + e.cost);
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n" << cycle.size() << endl;
        for (int v : cycle)
            cout << v + 1 << ' ';
        cout << endl;
    }
}
