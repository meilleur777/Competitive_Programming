#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;

    set<vector<int>> st;

    while (n--) {
        string s;
        cin >> s;
        vector<int> cnt(26, 0);
        for (auto c:s) cnt[c-'a']++;

        if (st.find(cnt)==st.end()) {
            cout << s << '\n';
            st.insert(cnt);
        }
    }

    return 0;
}
