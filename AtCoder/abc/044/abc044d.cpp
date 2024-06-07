#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n, s;
    cin >> n >> s;

    if (n<s) {
        cout << -1;
        return 0;
    }
    if (n==s) {
        cout << n+1;
        return 0;
    }

    long long k=1;
    for (; (k+1)*(k+1)<=n; k++);

    for (long long b=2; b<=k; b++) {
        long long sum=0;
        long long tmp=n;
        while (tmp) {
            sum+=tmp%b;
            tmp/=b;
        }

        if (sum==s) {
            cout << b;
            return 0;
        }
    }

    long long tmp=n-s;
    long long inf=0x7f7f7f7f7f7f7f7f;
    long long ans=inf;
    for (long long p=1; p*p<=tmp; p++) {
        if ((tmp)%(p)==0) {
            long long b=tmp/p+1;

            if (s==n/b+n%b) {
                ans=min(ans, b);
            }
        }
    }

    if (ans==inf) cout << -1;
    else cout << ans;

    return 0;
}
