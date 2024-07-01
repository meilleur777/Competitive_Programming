#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string s, p;
        cin >> s >> p;

        int ans=0;
        int ptr=0;
        while (ptr<(int)s.size()) {
            if (ptr+(int)p.size()-1<(int)s.size() &&
                s.substr(ptr, (int)p.size())==p) {
                ans++;
                ptr+=(int)p.size();
            }
            else {
                ans++;
                ptr++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
