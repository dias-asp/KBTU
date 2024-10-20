#include <bits/stdc++.h>
using namespace std;

map < string, string > M, change;
map < string, bool > used;
string S[2000];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s, s1;
        cin >> s >> s1;
        S[i] = s;
        M[s] = s1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (used[S[i]]) continue;
        string s = S[i];
        while (M[s] != "" && !used[s])
        {
            used[s] = true;
            s = M[s];
        }
        change[S[i]] = s;
    }

    cout << change.size() << endl;
    for (auto i : change) cout << i.first << " " << i.second << endl;
}
