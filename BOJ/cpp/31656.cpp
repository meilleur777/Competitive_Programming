#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    getline(cin, s, '\n');
    string ans=s.substr(0, 1);
    for (int i=1; i<(int)s.size(); i++) {
        if (s[i]==s[i-1]) continue;
        ans.push_back(s[i]);
    }
    cout << ans;

    return 0;
}
