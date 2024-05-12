#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    getline(cin, s, '\n');
    if (s[0]+s[4]-2*'0'==s[8]-'0') cout << "YES";
    else cout << "NO";

    return 0;
}
