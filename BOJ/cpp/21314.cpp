#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;

    string big, sml;

    int cnt=0;
    for (int i=0; i<(int)s.size(); i++) {
        if (s[i]=='M') {
            cnt++;
        }
        else {
            if (cnt) {
                big+="5"+string(cnt, '0');
                sml+="1"+string(cnt-1, '0')+"5";
                cnt=0;
            }
            else {
                big.push_back('5');
                sml.push_back('5');
            }
        }
    }
    if (cnt) {
        big+=string(cnt, '1');
        sml+="1"+string(cnt-1, '0');
    }

    cout << big << '\n' << sml;

    return 0;
}
