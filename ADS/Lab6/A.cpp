#include <bits/stdc++.h>
using namespace std;
bool cmp(char c1, char c2)
{
    if (c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u')
    {
        if (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u') return c1 < c2;
        return true;
    }
    if (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u') return false;
    return c1 < c2;
}
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(s.begin(), s.end(), cmp);
    cout << s;
}
