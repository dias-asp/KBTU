#include <bits/stdc++.h>
using namespace std;
string s;
bool ban[500000];
int S, K, cnts, cntk, n;
int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'K') K++;
        else S++;
    }
    while (S > 0 && K > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (ban[i]) continue;
            if (s[i] == 'K')
            {
                if (cnts > 0)
                {
                    ban[i] = 1;
                    cnts--;
                    K--;
                }
                else cntk++;
            }
            else
            {
                if (cntk > 0)
                {
                    ban[i] = 1;
                    cntk--;
                    S--;
                }
                else cnts++;
            }
        }
    }
    if (K > 0) cout << "KATSURAGI";
    if (S > 0) cout << "SAKAYANAGI";
}
