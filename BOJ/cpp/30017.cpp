#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    for (int i=a; i>=1; i--) {
        if (i-1<=b) {
            cout << i+i-1;
            break;
        }
    }

    return 0;
}
