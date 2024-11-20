#include <bits/stdc++.h>
#define int long long
using namespace std;
int prime = 31, mod = 1e9 + 7;
int n;
string s[10000];
char to_lower(char c){
    if (c >= 'A' && c <= 'Z') return c + 'a' - 'A';
    return c;
}
main(){
    string s1;
    cin >> s1 >> n;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
    }
    int mx = 0;
    vector < string > ans;
    for (int i = 1; i <= n; i++){
        int maxlen = min(s1.size(), s[i].size());
        for (int len = 1; len <= maxlen; len++){
            bool ok = 1;
            for (int j = 0; j < len; j++){
                //cout << s[i][j] << " " << s1[(int)s1.size()-len+j] << endl;
                if (to_lower(s[i][j]) != to_lower(s1[(int)s1.size()-len+j])) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                if (len > mx) {
                        ans.clear();
                        mx = len;
                }
                if (len == mx) ans.push_back(s[i]);
            }
        }
    }
    cout << ans.size() << endl;
    for (auto cur : ans) cout << cur << endl;
}
