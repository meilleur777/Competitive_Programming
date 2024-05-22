#include <bits/stdc++.h>
using namespace std;

//return a^b % p
long long power(long long a, long long b, long long p) {
    if (b==1) return a;
    long long tmp=power(a, b/2, p);
    tmp=tmp*tmp%p;
    if (b%2==1) return tmp*a%p;
    return tmp;
}

//For any integer a such that gcd(a, p) is 1,
//there exists another integer b such that ab≡1(mod p)
long long modInv(long long x, long long p) {
    return (power(x, p-2, p));
}

int main() {
    const long long mod=1e9+7;

    int bound=100;
    vector<long long> fact(bound);
    fact[0]=1;
    for (long long i=1; i<bound; i++) {
        fact[i]=fact[i-1]*i%mod;
    }

    cout << (modInv(103024, mod)*103024)%mod;

    return 0;
}
