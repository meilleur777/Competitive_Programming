#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> x(n);
    for (int i=0; i<n; i++) cin >> x[i];

    long long ans=0;
    for (int i=0; i<n-1; i++) {
        ans+=min(a*(x[i+1]-x[i]), b);
    }
    cout << ans;

    return 0;
}
