#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool flag=true;
        int cnt=0;
        for (int i=0; i<=(int)s.size()/2; i++) {
            cnt++;
            if (s[i]!=s[(int)s.size()-1-i]) {
                flag=false;
                break;
            }
        }
        if (flag) cout << 1 << ' ';
        else cout << 0 << ' ';
        cout << cnt << "\n";
    }

    return 0;
}
