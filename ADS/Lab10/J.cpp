#include <bits/stdc++.h>
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast")
using namespace std;
vector < int > g[100500];
int cnt, us[100500];
void dfs(int v, int p = -1){
    us[v] = 1;
    if (p == -1 || (int)g[v].size() - 1 > g[p].size()) cnt++;
    for (auto to : g[v]){
        if (to == p) continue;
        dfs(to, v);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++){
        if (us[i]) continue;
        dfs(i);
    }

    cout << cnt;
}
