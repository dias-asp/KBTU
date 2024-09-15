#include <bits/stdc++.h>
using namespace std;
queue < int > q1, q2;
int main()
{
    for (int i = 1; i <= 5; i++)
    {
        int x;
        cin >> x;
        q1.push(x);
    }
    for (int i = 1; i <= 5; i++)
    {
        int x;
        cin >> x;
        q2.push(x);
    }
    int moves = 0;
    while (moves < 1000000)
    {
        if (q1.empty()) break;
        if (q2.empty()) break;
        int x = q1.front();
        q1.pop();
        int y = q2.front();
        q2.pop();
        if (x == 0 && y == 9)
        {
            q1.push(x);
            q1.push(y);
        }
        else if (x == 9 && y == 0)
        {
            q2.push(x);
            q2.push(y);
        }
        else if (x > y)
        {
            q1.push(x);
            q1.push(y);
        }
        else
        {
            q2.push(x);
            q2.push(y);
        }
        moves++;
    }
    if (moves == 1000000) cout << "blin nichya";
    if (q1.empty()) cout << "Nursik " << moves;
    if (q2.empty()) cout << "Boris " << moves;
}
