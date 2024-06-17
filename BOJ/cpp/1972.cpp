#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    while (true) {
        string s;
        cin >> s;
        if (s=="*") break;

        int n=s.size();
        bool flag=true;
        for (int i=1; i<n; i++) {
            set<string> st;

            for (int j=0; j<n-i; j++) {
                string tmp="";
                tmp.push_back(s[j]);
                tmp.push_back(s[(j+i)%n]);
                st.insert(tmp);
            }

            if (st.size()!=n-i) {
                flag=false;
                break;
            }
        }

        if (flag) cout << s << " is surprising.\n";
        else cout << s << " is NOT surprising.\n";
    }

    return 0;
}
