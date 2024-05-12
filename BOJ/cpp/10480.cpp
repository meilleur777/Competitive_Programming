#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (abs(a)%2==0) cout << a << " is even\n";
        else cout << a << " is odd\n";
    }

    return 0;
}
