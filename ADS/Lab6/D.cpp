#include <bits/stdc++.h>
using namespace std;
string s[200500];
int year(string x)
{
    return stoi(x.substr(6, 4));
}
int mon(string x)
{
    return stoi(x.substr(3, 2));
}
int day(string x)
{
    return stoi(x.substr(0, 2));
}
bool cmp(string s1, string s2)
{
    if (year(s1) != year(s2)) return year(s1) < year(s2);
    if (mon(s1) != mon(s2)) return mon(s1) < mon(s2);
    return day(s1) < day(s2);
}
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; i++) cout << s[i] << endl;
}
