#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int mn = 1e6;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ans += x;
        mn = min(mn, x);
    }
    ans += mn * (n - 2);
    cout << ans;

}
