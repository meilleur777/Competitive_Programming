#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;
    string ans="";
    for (auto c:s) {
        if (c=='0') ans.push_back('0');
        else if (c=='1') ans.push_back('1');
        else {
            if (ans.empty()) continue;
            ans.pop_back();
        }
    }
    cout << ans;

    return 0;
}
