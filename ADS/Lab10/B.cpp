#include <bits/stdc++.h>
using namespace std;
int d[1050];
vector < int > g[1050];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if (x == 1) g[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++) d[i] = 1e9;

    int s, f;
    cin >> s >> f;
    d[s] = 0;
    queue < int > q;
    q.push(s);
    while (q.size()){
        int v = q.front();
        q.pop();
        for (auto to : g[v]){
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
    if (d[f] > 1000) cout << -1;
    else cout << d[f];
}
