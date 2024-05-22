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

int main() {
    const long long p=1e9+7;

    cout << power(3, 4, p);

    return 0;
}
