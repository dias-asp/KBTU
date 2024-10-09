#include <bits/stdc++.h>
using namespace std;
int a[100500], L[100500], R[100500];
stack < pair < int, int > > st1, st2;
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    st1.push({1000000000, n + 1});
    st2.push({0, n + 1});

    for (int i = n; i >= 1; i--)
    {
        while (st1.top().first < a[i]) st1.pop();
        while (st2.top().first > a[i]) st2.pop();
        R[i] = st1.top().second;
        L[i] = st2.top().second;
        st1.push({a[i], i});
        st2.push({a[i], i});
    }

    for (int i = 1; i <= m; i++)
    {
        string s;
        cin >> s;
        int x = 1;
        for (auto c : s)
        {
            if (c == 'L')
            {
                x = L[x];
            }
            else
            {
                x = R[x];
            }
            if (x == n + 1) break;
        }
        cout << (x == n + 1 ? "NO" : "YES") << endl;
    }
}
