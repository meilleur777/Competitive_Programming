#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    int ans=INT_MAX;
    for (int i=0; i<n-1; i++) {
        auto tmp=lower_bound(a.begin(), a.end(), a[i]+m);
        if (tmp==a.end()) continue;
        ans=min(ans, *tmp-a[i]);
    }
    cout << ans;

    return 0;
}
