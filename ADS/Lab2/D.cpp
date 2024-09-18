#include <iostream>

using namespace std;


int cnt[2000];

int main(){

    int n;
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
        if (cnt[x] > mx) mx = cnt[x];
    }
    for (int i = 1000; i >= 1; i--)
    {
        if (cnt[i] == mx) cout << i << " ";
    }
}
