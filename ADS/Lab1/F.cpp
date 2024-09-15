#include <bits/stdc++.h>
using namespace std;
int p[2000500];
vector < int > v;
int main()
{
    int n = 2000000;
    for (int i = 2; i <= n; i++) p[i] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (p[i])
        {
            v.push_back(i);
            for (int j = i + i; j <= n; j += i)
            {
                p[j] = 0;
            }
        }
    }

    cin >> n;
    cout << v[n - 1];
}
