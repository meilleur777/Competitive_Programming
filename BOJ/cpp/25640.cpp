#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    map<string, int> mp;
    string s;
    cin >> s;

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        string c;
        cin >> c;
        mp[c]++;
    }

    cout << mp[s];

    return 0;
}
