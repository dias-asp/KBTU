#include <bits/stdc++.h>
using namespace std;
multiset < int > S;
vector < int > add[200500], del[200500];
int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        int l, r, w;
        cin >> l >> r >> w;
        add[l].push_back(w);
        del[r].push_back(w);
    }
    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto x : del[i])
        {
            S.erase(S.find(x));
        }
        for (auto x : add[i])
        {
            S.insert(x);
        }

        ans += *S.begin();

    }
    cout << ans;

}
