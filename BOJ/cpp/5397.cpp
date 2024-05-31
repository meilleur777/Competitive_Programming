#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string l;
        cin >> l;

        list<char> lst;
        auto ptr=lst.end();

        for (auto c:l) {
            if (c=='<') {
                if (lst.empty()) continue;
                if (ptr!=lst.begin()) ptr--;
            }
            else if (c=='>') {
                if (lst.empty()) continue;
                if (ptr!=lst.end()) ptr++;
            }
            else if (c=='-') {
                if (lst.empty()) continue;
                if (ptr==lst.begin()) continue;
                auto tmp=ptr;
                ptr--;
                lst.erase(ptr);
                ptr=tmp;
            }
            else {
                lst.insert(ptr, c);
            }
        }

        for (auto i:lst) cout << i;
            cout << '\n';
    }

    return 0;
}
