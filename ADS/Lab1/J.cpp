#include <bits/stdc++.h>
using namespace std;
deque < int > d;
int main()
{
    char type;
    while (cin >> type)
    {
        if (type == '!') break;
        if (type == '+')
        {
            int x;
            cin >> x;
            d.push_front(x);
        }
        if (type == '-')
        {
            int x;
            cin >> x;
            d.push_back(x);
        }
        if (type == '*')
        {
            if (d.empty())
            {
                cout << "error\n";
                continue;
            }
            int x, y;
            x = d.front();
            y = d.back();
            d.pop_front();
            if (!d.empty()) d.pop_back();
            cout << x + y << endl;
        }
    }
}
