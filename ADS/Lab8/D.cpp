#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9 + 7;
string s1[1000];
vector < string > ans;
signed main(){
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0) break;
        ans.clear();
        for (int i = 1; i <= n; i++) cin >> s1[i];
        string s;
        cin >> s;
        int mx = 0;
        for (int i = 1; i <= n; i++)
        {
            int h1 = 0;
            int power = 1;
            for (int j = 0; j < s1[i].size(); j++)
            {
                h1 = (h1 * 37 + (s1[i][j] - 'a' + 1)) % mod;
            }
            int h = 0;
            for (int j = 0; j < s1[i].size() - 1; j++)
            {
                power = (power * 37) % mod;
                h = (h * 37 + (s[j] - 'a' + 1)) % mod;
            }
            int cnt = 0;
            for (int j = s1[i].size() - 1; j < s.size(); j++)
            {

                h = (h * 37 + (s[j] - 'a' + 1)) % mod;

                if (h1 == h)
                {
                    cnt++;
                }

                h = (h - power * (s[j - s1[i].size() + 1] - 'a' + 1) % mod + mod) % mod;
            }
            if (cnt > mx)
            {
                ans.clear();
                mx = cnt;
            }
            if (cnt == mx) ans.push_back(s1[i]);
        }

        cout << mx << endl;
        for (auto i : ans) cout << i << endl;
    }
}
