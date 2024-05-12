#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans=0;
        for (int x=1; x<=a; x++) {
            for (int y=1; y<=b; y++) {
                for (int z=1; z<=c; z++) {
                    if (x%y==y%z && y%z==z%x) ans++;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
