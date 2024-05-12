#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    set<char> st;
    string s;
    cin >> s;
    for (auto c:s) st.insert(c);

    string chk="MOBIS";
    for (auto c:chk) {
        if (st.find(c)==st.end()) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}
