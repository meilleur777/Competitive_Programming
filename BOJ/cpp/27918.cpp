#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    int x=0, y=0;
    bool flag=false;
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        if (c=='D') x++;
        else y++;

        if (flag==false && abs(x-y)>=2) {
            flag=true;
            cout << x << ":" << y;
        }
    }

    if (!flag) cout << x << ":" << y << "\n";

    return 0;
}
