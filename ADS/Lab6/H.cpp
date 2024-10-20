#include <bits/stdc++.h>
using namespace std;

char c[200500];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    char x;
    cin >> x;
    int l = 1;
    int r = n;
    char ans = c[1];
    while (l <= r)
    {
        int mi = (l + r) / 2;
        if (c[mi] > x)
        {
            r = mi - 1;
            ans = c[mi];
        }
        else
        {
            l = mi + 1;
        }
    }
    cout << ans;
}
