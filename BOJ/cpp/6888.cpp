#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    for (int i=a; i<=b; i+=60) {
        cout << "All positions change in year " << i << '\n';
    }

    return 0;
}
