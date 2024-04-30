#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<long long> c(n);
    for (int i=0; i<n; i++) cin >> c[i];

    sort(c.begin(), c.end());
    long long maxc=c.back();
    long long S=0, M=0;
    for (int i=0; i<n-k; i++) S+=c[i];
    for (int i=n-k; i<n; i++) M+=c[i];

    long long ans=-1;
    if (maxc*k-M<S) ans=(M+S+k-1)/k*k-M-S;
    else ans=maxc*k-M-S;
    cout << ans;

    return 0;
}
