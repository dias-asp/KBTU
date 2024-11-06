#include <bits/stdc++.h>
using namespace std;
string s[1000];
string s1;
bool cmp(string s1, string s2)
{
    if (s1.size() == s2.size()) return s1 < s2;
    else return s1.size() < s2.size();
}
int main()
{
    int n;
    cin >> n;
    getline(cin, s1);
    while (n--)
    {
        getline(cin, s1);
        //s1 += ' ';
        int id = 0;
        for (auto c : s1)
        {
            if (c == ' ') id++;
            else s[id] += c;
        }
        for (int i = 0; i <= id; i++)
        {
            for (int j = 0; j < id; j++)
            {
                if (s[j].size() > s[j + 1].size()) swap(s[j], s[j + 1]);
            }
        }
        for (int i = 0; i <= id; i++) cout << s[i] << " ";
        cout << endl;
        for (int i = 0; i <= id; i++) s[i] = "";
    }
}
