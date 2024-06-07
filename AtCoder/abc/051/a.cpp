#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;
    size_t ptr;
    while ((ptr=s.find(","))!=s.npos) {
        cout << s.substr(0, ptr) << ' ';
        s.erase(0, ptr+1);
    }
    cout << s;

    return 0;
}
