#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    const long long mod=1e9+7;

    long long ans=0;
    long long now=1;
    for (int i=0; i<n; i++) {
        ans=(ans+now*v[i]%mod)%mod;
        now=(now*2)%mod;
    }
    
    cout << ans;
    

    return 0;
}
