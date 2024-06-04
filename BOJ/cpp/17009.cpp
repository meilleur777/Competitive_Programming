#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
        
    vector<int> a(2, 0);
    for (int j=0; j<2; j++) {
        for (int i=3; i>=1; i--) {
            int c;
            cin >> c;
            a[j]+=c*i;
        }
    }

    if (a[0]>a[1]) cout << "A";
    else if (a[0]<a[1]) cout << "B";
    else cout << "T";

    return 0;
}
