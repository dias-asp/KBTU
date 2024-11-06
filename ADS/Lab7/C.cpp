#include <bits/stdc++.h>
using namespace std;
int a[200500], b[200500];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int id1 = 1;
    int id2 = 1;
    while (id1 <= n && id2 <= m)
    {
        if (a[id1] < b[id2]) id1++;
        else if (a[id1] > b[id2]) id2++;
        else if (a[id1] == b[id2])
        {
            cout << a[id1] << " ";
            id1++;
            id2++;
        }
    }
}
