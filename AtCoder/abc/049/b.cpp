#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int h, w;
    cin >> h >> w;
    vector<string> brd(h);
    for (int i=0; i<h; i++) cin >> brd[i];

    for (auto s:brd) {
        for (int i=0; i<2; i++) cout << s << '\n';
    }

    return 0;
}
