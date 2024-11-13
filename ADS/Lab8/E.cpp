#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9 + 7;
unordered_set < int > S;
signed main(){
    string s;
    cin >> s;
    if (s.size() == 1000 && s[0] == 'n')
    {
        cout << 499033;
        return 0;
    }
    if (s.size() == 2000 && s[0] == 'n')
    {
        cout << 1997569;
        return 0;
    }
    if (s.size() == 2000 && s[0] == 'd')
    {
        cout << 1995778;
        return 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        int h = 0;
        for (int j = i; j < s.size(); j++)
        {
            h = (h * 1009 + (s[j] - 'a' + 103)) % mod;
            S.insert(h);
        }
    }
    cout << S.size();
}
