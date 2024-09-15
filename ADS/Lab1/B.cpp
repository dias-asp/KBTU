#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // 21583
    // -1 -1 1 5 1
    stack<int> st;

    for (int i = n - 1; i > -1; i--)
    {
        for (int j = i - 1; j > (-1); j--)
        {

            if (a[j] <= a[i])
            {
                st.push(a[j]);
                break;
            }

            if (j == 0)
            {
                st.push(-1);
            }
        }
    }
    st.push(-1);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
