#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;
    string tmp="";
    int n=s.size();
    tmp.push_back(s[0]);
    for (int i=1; i<n; i++) {
        if (s[i-1]==s[i]) continue;
        tmp.push_back(s[i]);
    }

    cout << (int)tmp.size()-1;

    return 0;
}
