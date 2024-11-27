#include <bits/stdc++.h>
using namespace std;
int a[1050][1050], d[1050][1050];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int main(){
    int n, m;
    cin >> n >> m;
    queue < pair < int, int > > q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if (a[i][j] == 2) q.push({i, j});
            if (a[i][j] == 1) d[i][j] = 1e9;
        }
    }

    while (q.size()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if (a[x][y] == 1) {
                a[x][y] = 2;
                d[x][y] = d[i][j] + 1;
                q.push({x, y});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            ans = max(ans, d[i][j]);
        }
    }
    if (ans == 1e9) cout << -1;
    else cout << ans;
}
