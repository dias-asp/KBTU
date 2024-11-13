#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s[100000];
map < string, ll > ans, us;
map < ll, int > M;
vector < string > v;
int mod = 1e9 + 7;

int get_hash(string x){
    ll h = 0;
    ll power = 1;
    for (auto c : x)
    {
        h += ((c - 47) * power) % mod;
        h %= mod;
        power *= 11;
        power %= mod;
    }
    return h;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n + n; i++){
        cin >> s[i];
        if (s[i].size() < 11) M[stoll(s[i])] = i;
    }

    for (int i = 1; i <= n + n; i++){
        if (us[s[i]]) continue;
        int x = get_hash(s[i]);
        if (M[x])
        {
            cout << "Hash of string \"" << s[i] << "\" is " << x<< endl;
            us[to_string(x)] = 1;
        }
    }
    for (int i = 1; i <= n + n; i++){
        if (us[s[i]]) continue;
        if (ans[s[i]]) cout << "Hash of string \"" << s[i] << "\" is " << ans[s[i]] << endl;
    }
}
