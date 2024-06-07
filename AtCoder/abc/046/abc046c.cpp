#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> t(n), a(n);
    for (int i=0; i<n; i++) {
        cin >> t[i] >> a[i];
    }

    long long ttt=t[0], aaa=a[0];
    for (int i=1; i<n; i++) {
        long long tmp=max((ttt+t[i]-1)/t[i], (aaa+a[i]-1)/a[i]);
        ttt=t[i]*tmp;
        aaa=a[i]*tmp;
    }

    cout << ttt+aaa;

    return 0;
}
