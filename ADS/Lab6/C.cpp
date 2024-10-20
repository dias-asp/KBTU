#include <bits/stdc++.h>
using namespace std;
int a[200500];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int mn = 2e7;
    for (int i = 2; i <= n; i++)
    {
        mn = min(mn, abs(a[i] - a[i - 1]));
    }

    for (int i = 2; i <= n; i++)
    {
        if (abs(a[i] - a[i - 1]) == mn) cout << a[i - 1] << " " << a[i] << " ";
    }
}
