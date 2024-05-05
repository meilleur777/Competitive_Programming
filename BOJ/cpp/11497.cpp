#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) cin >> v[i];

        int ans=-1;
        sort(v.begin(), v.end());
        for (int i=0; i<n-2; i+=2) ans=max(ans, v[i+2]-v[i]);
        for (int i=1; i<n-2; i+=2) ans=max(ans, v[i+2]-v[i]);

        cout << ans << '\n';
    }

    return 0;
}
