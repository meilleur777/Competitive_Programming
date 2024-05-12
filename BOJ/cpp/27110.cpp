#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    int ans=0;
    for (int i=0; i<3; i++) {
        int a;
        cin >> a;
        ans+=min(a, n);
    }
    cout << ans << '\n';

    return 0;
}
