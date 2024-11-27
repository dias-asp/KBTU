#include <bits/stdc++.h>
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast")
using namespace std;
vector < int > ts, g[100500];
int us[100500];
void dfs(int v){
    us[v] = 1;
    for (auto to : g[v]){
        if (us[to] == 1) {
            cout << "Impossible";
            exit(0);
        }
        if (us[to] == 2) continue;
        dfs(to);
    }
    us[v] = 2;
    ts.push_back(v);
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; i++){
        if (us[i]) continue;
        dfs(i);
    }

    reverse(ts.begin(), ts.end());
    cout << "Possible\n";
    for (auto i : ts) cout << i << " ";
}
