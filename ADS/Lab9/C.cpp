#include <bits/stdc++.h>
#define int long long
using namespace std;
int prime = 337, mod = 1e9 + 7;
main(){
    string s, s1;
    cin >> s >> s1;
    s1 += s1;

    int h = 0;
    for (auto c : s)
    {
        h = (h * prime + (c)) % mod;
    }
    int h1 = 0;
    int power = 1;
    for (int i = 0; i < s.size() - 1; i++)
    {
        power = (power * prime) % mod;
        h1 = (h1 * prime + (s1[i])) % mod;
    }
    int cnt = 0;
    for (int i = s.size() - 1; i < s1.size(); i++)
    {
        h1 = (h1 * prime + (s1[i])) % mod;


        if (h == h1)
        {
            cout << i - s.size() + 1;
            return 0;
        }

        h1 = (h1 - power * (s1[i - s.size() + 1]) % mod + mod) % mod;
    }
    cout << -1;
}
