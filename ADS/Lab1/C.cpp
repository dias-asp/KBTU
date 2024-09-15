#include <bits/stdc++.h>
using namespace std;
string s;
stack < char > st1, st2;
int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#') st1.pop();
        else st1.push(s[i]);
    }
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#') st2.pop();
        else st2.push(s[i]);
    }
    if (st1 == st2) cout << "Yes";
    else cout << "No";
}
