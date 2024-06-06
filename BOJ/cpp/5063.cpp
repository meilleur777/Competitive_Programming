#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    while (n--) {
        int r, e, c;
        cin >> r >> e >> c;
        if (r>e-c) cout << "do not advertise\n";
        else if (r==e-c) cout << "does not matter\n";
        else cout << "advertise\n";
    }

    return 0;
}
