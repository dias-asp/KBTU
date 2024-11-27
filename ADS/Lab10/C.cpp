#include <bits/stdc++.h>
using namespace std;
int d[20500], p[20500];
int main(){
    int x, y;
    cin >> x >> y;
    vector < int > ans;
    queue < int > q;
    for (int i = 1; i <= 20000; i++) d[i] = 1e9;
    d[x] = 0;
    q.push(x);
    while (q.size()){
        int v = q.front();
        q.pop();
        int to = v + v;
        if (to <= 20000 && d[to] > d[v] + 1){
            d[to] = d[v] + 1;
            p[to] = v;
            q.push(to);
        }
        to = v - 1;
        if (to > 1 && d[to] > d[v] + 1){
            d[to] = d[v] + 1;
            p[to] = v;
            q.push(to);
        }
    }
    cout << d[y] << endl;
    while (y != x){
        ans.push_back(y);
        y = p[y];
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i << " ";
}
