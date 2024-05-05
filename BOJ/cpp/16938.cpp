#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans=0;
    for (int i=0; i<(1<<n); i++) {
        vector<int> b;
        int sum=0;
        for (int j=0; j<n; j++) {
            if (!(i&(1<<j))) continue;
            b.push_back(a[j]);
            sum+=a[j];
        }

        if ((int)b.size()>=2 && l<=sum && sum<=r && b.back()-b.front()>=x) ans++;
    }
    cout << ans;

    return 0;
}
