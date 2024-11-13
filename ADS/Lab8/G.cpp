#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9 + 7;
unordered_map < int, int > cnt[3000];
int prime = 2053, add = 51;
signed main(){
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        int h = 0;
        for (int j = i; j < s.size(); j++)
        {
            h = (h * prime + (s[j] - 'a' + add)) % mod;
            cnt[j-i+1][h]++;
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        int h = 0;
        for (int j = l - 1; j <= r - 1; j++)
        {
            h = (h * prime + (s[j] - 'a' + add)) % mod;
        }
        cout << cnt[r-l+1][h] << endl;
    }
}
