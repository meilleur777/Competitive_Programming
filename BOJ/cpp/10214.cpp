#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int y=0, k=0;
        for (int i=0; i<9; i++) {
            int a, b;
            cin >> a >> b;
            y+=a, k+=b;
        }
        if (y>k) cout << "Yonsei\n";
        else if (y==k) cout << "Draw\n";
        else if (y<k) cout << "Korea\n";
    }

    return 0;
}
