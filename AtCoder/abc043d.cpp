#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;
    int n=s.size();
    if (n==2) {
        if (s[0]==s[1]) cout << 1 << ' ' << 2;
        else cout << -1 << ' ' << -1;
    }
    else {
        for (int i=0; i<n-2; i++) {
            string tmp=s.substr(i, 3);
            vector<bool> isIn(26, false);
            for (int j=0; j<3; j++) {
                if (isIn[tmp[j]-'a']) {
                    cout << i+1 << ' ' << i+3;
                    return 0;
                }
                isIn[tmp[j]-'a']=true;
            }
        }
        cout << -1 << ' ' << -1;
    }

    return 0;
}
