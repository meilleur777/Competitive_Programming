#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int mx=a[n-1];
    vector<int> v(n, 0);
    for (int i=n-2; i>=0; i--) {
        v[i]=max(0, mx-a[i]);
        mx=max(mx, a[i]);
    }

    int ans=0;
    int proMx=*max_element(v.begin(), v.end());
    for (int i=0; i<n; i++) {
        ans+=proMx==v[i];
    }
    cout << ans;

    return 0;
}
