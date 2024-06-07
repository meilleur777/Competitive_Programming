#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    char c;
    cin >> c;
    string s="aeiou";
    if (s.find(c)==s.npos) {
        cout << "consonant";
    }
    else cout << "vowel";

    return 0;
}
