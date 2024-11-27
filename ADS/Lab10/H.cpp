#include <bits/stdc++.h>
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast")
using namespace std;
char c[200][200];
int us[200][200];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void dfs(int x, int y){
    us[x][y] = 1;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (c[nx][ny] == '1' && !us[nx][ny]) dfs(nx, ny);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) cin >> c[i][j];
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (c[i][j] == '1' && !us[i][j])
            {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt;
}
