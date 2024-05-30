#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    for (int i=0; i<n; i++) {
        string s=v[i];

        if ((int)s.size()>10) continue;

        int upperCnt=0, lowerCnt=0;
        for (auto c:s) {
            if (isupper(c)) upperCnt++;
            if (islower(c)) lowerCnt++;
        }

        if (upperCnt>lowerCnt) continue;

        bool flag=false;
        for (auto c:s) {
            if (!isdigit(c)) flag=true;
        }
        if (!flag) continue;

        cout << s;
        break;
    }

    return 0;
}
