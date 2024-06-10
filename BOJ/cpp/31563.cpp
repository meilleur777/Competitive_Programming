#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<long long> presum(n);
    presum[0]=a[0];
    for (int i=1; i<n; i++) {
        presum[i]=presum[i-1]+a[i];
    }

    function<long long(int, int)> getsum=[&](int a, int b) {
        if (a==0) return presum[b];
        return presum[b]-presum[a-1];
    };

    int offset=0;
    while (q--) {
        int ope;
        cin >> ope;
        if (ope==1) {
            int k;
            cin >> k;
            offset=(offset-k+n)%n;
        }
        else if (ope==2) {
            int k;
            cin >> k;   
            offset=(offset+k+n)%n;
        }
        else {
            int a, b;
            cin >> a >> b;
            a--, b--;

            a=(a+offset+n)%n;
            b=(b+offset+n)%n;

            if (a<=b) {
                cout << getsum(a, b) << '\n';
            }
            else {
                cout << getsum(0, b)+getsum(a, n-1) << '\n';
            }
        }
    }

    return 0;
}
