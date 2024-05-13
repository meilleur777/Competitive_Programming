#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<long double> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    long double sum0=1e-6, sum1=1e-6;
    for (int i=k; i<n-k; i++) {
        sum0+=a[i];
        sum1+=a[i];
    }
    for (int i=0; i<k; i++) {
        sum1+=a[k];
        sum1+=a[n-k-1];
    }
    sum0/=n-2*k;
    sum1/=n;

    cout.setf(ios_base::fixed);
    cout << setprecision(2) << sum0 << '\n';
    cout << setprecision(2) << sum1 << '\n';

    return 0;
}
