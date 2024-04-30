#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

long long power(long long a, long long b) {
    if (b == 1) return a;
    long long temp = power(a, b/2);
    temp = temp*temp%mod;
    if (b%2) return temp*a%mod;
    else return temp;
}

long long modInv(long long a, long long b) {
    return power(a, b-2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    long long n, k;
    cin >> n >> k;

    vector<long long> fac(n+1);
    fac[0] = 1;
    for (long long i=1; i<=n; i++) {
        fac[i]=fac[i-1]*i%mod;
    }

    long long res=fac[n] * (modInv(fac[k], mod)%mod) * (modInv(fac[n-k], mod)%mod) %mod;
    cout << res;    

    return 0;
}
