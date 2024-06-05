#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long ret=1;
    while (exp) {
        if (exp%2==1) ret=ret*base%mod;
        base=base*base%mod;
        exp/=2;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t=0;
    cin >> t;
    for (int caseNum=1; caseNum<=t; caseNum++) {
        long long a, n, p;
        cin >> a >> n >> p;

        long long ans=a%p;
        for (int i=2; i<=n; i++) {
            ans=power(ans, i, p);
        }

        cout << "Case #" << caseNum << ": " << ans << '\n';
    }

    return 0;
}
