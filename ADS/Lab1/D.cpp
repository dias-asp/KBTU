#include <bits/stdc++.h>
using namespace std;
string s;
stack < char > st;
int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (st.size() > 0 && st.top() == s[i]) st.pop();
        else st.push(s[i]);
    }
    if (st.size() == 0) cout << "YES";
    else cout << "NO";
}
