#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    for (int j=1; j<=n; j++) {
        int ans=-1;
        for (int i=0; i<5; i++) {
            int a;
            cin >> a;
            ans=max(ans, a);
        }
        cout << "Case #" << j << ": " << ans << '\n';
    }

    return 0;
}
