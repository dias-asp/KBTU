#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}
main(){
    string s, s1;
    cin >> s >> s1;
    string t = s1 + '#' + s;
    vector < int > v = prefix_function(t);
    vector < int > ans;
    for (int i = s1.size(); i < v.size(); i++){
        if (v[i] == s1.size()) ans.push_back(i - s1.size() * 2 + 1);
    }
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << " ";
}
