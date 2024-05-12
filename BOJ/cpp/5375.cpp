#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        string ans="";
        for (auto c:s) {
            if (!ans.empty() && ans.back()==c) continue;
            ans.push_back(c);
        }
        cout << ans << '\n';
    }

    return 0;
}
