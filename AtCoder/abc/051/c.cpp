#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    cout << string(ty-sy, 'U');
    cout << string(tx-sx, 'R');
    cout << string(ty-sy, 'D');
    cout << string(tx-sx, 'L');
    cout << "L";
    cout << string(ty-sy+1, 'U');
    cout << string(tx-sx+1, 'R');
    cout << "D";
    cout << "R";
    cout << string(ty-sy+1, 'D');
    cout << string(tx-sx+1, 'L');
    cout << "U";

    return 0;
}
