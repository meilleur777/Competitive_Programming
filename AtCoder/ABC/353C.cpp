#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    long long ans=0;
    int mod=1e8;
    vector<int> v(n+1);
    for (int i=1; i<=n; i++) cin >> v[i];

    vector<int> presum(n+1, 0);
    for (int i=1; i<=n; i++) {
        presum[i]=presum[i-1]+v[i];
    }

    for (int i=1; i<=n; i++) {
        int tmp=v[i]*(n-i-1)+presum[n]-presum[i-1];
        tmp-=min(n-i, tmp/mod)*mod;
        ans+=tmp;
    }

    cout << ans;

    return 0;
}
