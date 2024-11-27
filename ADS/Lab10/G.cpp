#include <bits/stdc++.h>
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast")
using namespace std;
int ban[1000][1000], us[100500];
vector < int > g[100500];
pair < int, int > p[100500];
bool ok;
void dfs(int v){
    us[v] = 1;
    for (auto to : g[v]){
        if (ban[v][to]) continue;
        if (us[to] == 1){
            ok = 0;
            return;
        }
        if (us[to] == 2) continue;
        dfs(to);
        if (!ok) return;
    }
    us[v] = 2;
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        p[i] = {x, y};
    }
    for (int i = 1; i <= m; i++){
        ban[p[i].first][p[i].second] = 1;
        for (int i = 1; i <= n; i++) us[i] = 0;
        ok = 1;
        for (int i = 1; i <= n; i++){
            if (us[i]) continue;
            dfs(i);
            if (!ok) break;
        }
        if (ok){
            cout << "YES";
            return 0;
        }
        ban[p[i].first][p[i].second] = 0;
    }
    cout << "NO";
}
