#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    long long ans=0;
    for (int i=0; i<n-1; i++) {
        if (a[i]+a[i+1]>x) {
            long long tmp=a[i]+a[i+1]-x;
            long long mn=min(a[i+1], tmp);
            a[i+1]-=mn;
            ans+=tmp;
        }
    }
    cout << ans;

    return 0;
}
