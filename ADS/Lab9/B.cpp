#include <bits/stdc++.h>
#define int long long
using namespace std;
int prime = 31, mod = 1e9 + 7;
main(){
    string s, s1;
    int k;
    cin >> s >> k >> s1;

    int h = 0;
    for (auto c : s)
    {
        h = (h * prime + (c - 'a' + 1)) % mod;
    }
    int h1 = 0;
    int power = 1;
    for (int i = 0; i < s.size() - 1; i++)
    {
        power = (power * prime) % mod;
        h1 = (h1 * prime + (s1[i] - 'a' + 1)) % mod;
    }
    int cnt = 0;
    for (int i = s.size() - 1; i < s1.size(); i++)
    {
        h1 = (h1 * prime + (s1[i] - 'a' + 1)) % mod;

        if (h == h1) cnt++;

        h1 = (h1 - power * (s1[i - s.size() + 1] - 'a' + 1) % mod + mod) % mod;
    }
    cout << (cnt >= k ? "YES" : "NO");
}
