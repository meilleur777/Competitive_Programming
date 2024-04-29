#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        regex r(R"((100+1+|01)+)");
        cout << (regex_match(s, r) ? "YES" : "NO") << '\n';
    }

    return 0;
}
