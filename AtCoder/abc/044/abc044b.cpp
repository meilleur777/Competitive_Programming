#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string w;
    cin >> w;
    vector<int> cnt(26, 0);
    for (auto c:w) {
        cnt[c-'a']++;
    }

    for (auto a:cnt) {
        if (a%2==1) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";

    return 0;
}
