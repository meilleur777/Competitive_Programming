#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    while (true) {
        cin >> n;
        if (n==0) break;
        for (int i=0; i<n; i++) {
            cout << string(i+1, '*') << '\n';
        }
    }

    return 0;
}
