#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9 + 7, add[100500], del[100500];
signed main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s1;
        cin >> s1;
        int h1 = 0;
        int power = 1;
        for (int j = 0; j < s1.size(); j++)
        {
            h1 = (h1 * 37 + (s1[j] - 'a' + 1)) % mod;
        }
        int h = 0;
        for (int j = 0; j < s1.size() - 1; j++)
        {
            power = (power * 37) % mod;
            h = (h * 37 + (s[j] - 'a' + 1)) % mod;
        }
        for (int j = s1.size() - 1; j < s.size(); j++)
        {

            h = (h * 37 + (s[j] - 'a' + 1)) % mod;
            //cout << h1 << " " << h2 << endl;

            if (h1 == h)
            {
                add[j - s1.size() + 1]++;
                del[j]++;
            }

            h = (h - power * (s[j - s1.size() + 1] - 'a' + 1) % mod + mod) % mod;
        }
    }

    int x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        x += add[i];
        if (x == 0)
        {
            cout << "NO";
            return 0;
        }
        x -= del[i];
    }
    cout << "YES";

}
