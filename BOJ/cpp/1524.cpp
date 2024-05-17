#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int smx=-1, bmx=-1;
        while (n--) {
            int a;
            cin >> a;
            smx=max(smx, a);
        }
        while (m--) {
            int a;
            cin >> a;
            bmx=max(bmx, a);
        }
        if (smx<bmx) cout << "B\n";
        else cout << "S\n";
    }

    return 0;
}
