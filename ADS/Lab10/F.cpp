#include <bits/stdc++.h>
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast")
using namespace std;
int c[100500], us[100500];
vector < int > g[100500];
int cnt;
void dfs(int v){
    us[v] = 1;
    c[v] = cnt;
    for (auto to : g[v]){
        if (us[to]) continue;
        dfs(to);
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
        cnt++;
        dfs(i);
    }
    int x, y;
    cin >> x >> y;
    if (c[x] == c[y]) cout << "YES";
    else cout << "NO";
}
