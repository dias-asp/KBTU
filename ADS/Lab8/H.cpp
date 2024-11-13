#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9 + 7;
unordered_map < int, int > cnt[11][3000];
string s[11];
int prime = 37;
signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); j++)
        {
            int h = 0;
            for (int k = j; k < s[i].size(); k++)
            {
                h = (h * prime + (s[i][k] - 'a' + 1)) % mod;
                cnt[i][k-j+1][h] = 1;
                //cout << i << " " << k-j+1 << " " << h << endl;
            }
        }
    }
    //cout << endl << endl;
    int ans = 0;
    int mx = 0;
    for (int j = 0; j < s[1].size(); j++)
    {
        int h = 0;
        for (int k = j; k < s[1].size(); k++)
        {
            h = (h * prime + (s[1][k] - 'a' + 1)) % mod;
            bool ok = 1;
            for (int i = 2; i <= n; i++)
            {
                if (cnt[i][k-j+1][h] == 0)
                {
                    ok = 0;
                    break;
                }
            }
            //cout << k-j+1 << " " << h << " " << ok << endl;
            if (!ok) break;
            if (k-j+1 > mx)
            {
                mx = k-j+1;
                ans = j;
            }
        }
    }
    for (int i = ans; i <= ans+mx-1; i++) cout << s[1][i];
}
