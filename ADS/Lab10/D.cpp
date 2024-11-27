#include <bits/stdc++.h>
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast")
using namespace std;
int d[10500];
vector < int > g[10500];
int main(){
    int n, m, w;
    cin >> n >> m >> w;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector < int > red, visited;
    int type, x;
    for (int i = 1; i <= n; i++) d[i] = n + 1;
    while (w--){
        cin >> type >> x;
        if (type == 1){
            queue < int > q;
            q.push(x);
            d[x] = 0;
            while (!q.empty()){
                int v = q.front();
                q.pop();
                for (int to : g[v]){
                    if (d[to] > d[v] + 1) {
                        d[to] = d[v] + 1;
                        q.push(to);
                    }
                }
            }
        }
        else{
            if (d[x] == n + 1) cout << -1;
            else cout << d[x];
            cout << '\n';
        }
    }
}
