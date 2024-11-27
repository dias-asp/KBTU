#include <bits/stdc++.h>
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast")
using namespace std;
int a[1050][1050];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if (a[x][y] && a[x][z] && a[y][z]) cout << "YES\n";
        else cout << "NO\n";
    }
}
