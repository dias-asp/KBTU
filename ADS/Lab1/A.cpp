#include <bits/stdc++.h>
using namespace std;
int n, test;
int main()
{
    cin >> test;
    for (int _ = 1; _ <= test; _++)
    {
        queue < int > q;
        cin >> n;

        q.push(n);
        for (int i = n - 1; i >= 1; i--)
        {
            q.push(i);
            for (int j = 1; j <= i; j++)
            {
                int x = q.front();
                q.pop();
                q.push(x);
            }
        }
        stack < int > ans;
        while (q.size() > 0)
        {
            ans.push(q.front());
            q.pop();
        }
        while (ans.size() > 0)
        {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }

}
