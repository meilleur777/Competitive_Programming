#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;
    s=s.substr(0, 5);

    map<string, int> mp;

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        string c;
        cin >> c;
        c=c.substr(0, 5);
        mp[c]++;
    }

    cout << mp[s];

    return 0;
}
