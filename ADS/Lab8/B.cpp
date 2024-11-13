#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    string s1, s2;
    cin >> s1 >> s2;
    string s;
    cin >> s;
    int h = 0, h1 = 0, h2 = 0;
    int power = 1;
    int mod = 1e9 + 7;
    for (int i = 0; i < s.size(); i++)
    {
        h = (h * 37 + (s[i] - 'a' + 1)) % mod;
        if (i > 0) power = (power * 37) % mod;

        if (i == s.size() - 1) continue;
        h1 = (h1 * 37 + (s1[i] - 'a' + 1)) % mod;
        h2 = (h2 * 37 + (s2[i] - 'a' + 1)) % mod;
    }
    int cnt = 0;
    for (int i = s.size() - 1; i < s1.size(); i++)
    {
        h1 = (h1 * 37 + (s1[i] - 'a' + 1)) % mod;
        h2 = (h2 * 37 + (s2[i] - 'a' + 1)) % mod;
        //cout << h1 << " " << h2 << endl;

        if (h1 == h2 && h1 == h) cnt++;

        h1 = (h1 - power * (s1[i - s.size() + 1] - 'a' + 1) % mod + mod) % mod;
        h2 = (h2 - power * (s2[i - s.size() + 1] - 'a' + 1) % mod + mod) % mod;
    }
    cout << cnt;
}
