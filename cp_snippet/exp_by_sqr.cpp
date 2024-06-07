#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp, long long mod) {
    if (exp==1) return base;
    long long tmp=power(base, exp/2, mod);
    tmp=tmp*tmp%mod;
    if (exp%2==1) return tmp*base%mod;
    return tmp;
}

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
    const long long p=1e9+7;

    cout << power(3, 4, p);

    return 0;
}
