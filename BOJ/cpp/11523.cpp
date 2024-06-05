#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int p;
    cin >> p;
    while (p--) {
        int k, s;
        cin >> k >> s;
        cout << k << ' ';

        if (s%2) {
            cout << 0 << '\n';
            continue;
        }

        s/=2;

        long long ans=0;
        long long comb=1;
        if (s%2) comb=s/2+1;

        for (int i=s/2; s-i*2<=i; i--) {
            long long one=s-i*2;
            long long two=i;

            ans+=comb*comb;

            comb=comb*(two+one+1)*two;
            comb/=(one+2)*(one+1);
        }
        cout << ans << '\n';
    }

    return 0;
}
