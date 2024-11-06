#include <bits/stdc++.h>
using namespace std;
int n, m;
bool cmp(vector < int > v1, vector < int > v2)
{
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < m; i++)
    {
        sum1 += v1[i];
        sum2 += v2[i];
    }
    if (sum1 == sum2) return v1 < v2;
    return sum1 > sum2;
}
int main()
{
    cin >> n >> m;
    vector < int > a[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
