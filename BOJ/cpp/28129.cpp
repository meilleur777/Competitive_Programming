#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
    }

    const long long mod=1e9+7;
    vector<vector<long long>> cache(n, vector<long long>(3e3+1, 0));
    for (int i=a[0]; i<=b[0]; i++) {
        cache[0][i]=i-a[0]+1;
    }

    function<long long(const vector<long long>&, int, int)> 
    getsum=[&](const vector<long long>& v, int left, int right) {
        if (left>right) return 0LL;
        return (v[right]-v[left-1]+mod)%mod;
    };

    for (int i=1; i<n; i++) {
        for (int j=a[i]; j<=b[i]; j++) {
            cache[i][j]=getsum(cache[i-1], max(j-k, a[i-1]), min(j+k, b[i-1]));
        }

        for (int j=a[i]+1; j<=b[i]; j++) {
            cache[i][j]+=cache[i][j-1];
            cache[i][j]%=mod;
        }
    }

    cout << cache[n-1][b[n-1]];

    return 0;
}
