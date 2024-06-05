#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b) {
    if (b==0) return 1LL;
    long long tmp=power(a, b/2);
    tmp=tmp*tmp;
    if (b%2) return tmp*a;
    return tmp;
}

void sieve(int bound, vector<long long>& prime) {
    vector<bool> isPrime(bound+1, true);
    isPrime[0]=isPrime[1]=false;

    for (int i=2; i<=bound; i++) {
        if (!isPrime[i]) continue;
        prime.push_back(i);

        for (int j=i*2; j<=bound; j+=i) {
            isPrime[j]=false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    const int bound=1e7;    
    vector<long long> prime;
    sieve(bound, prime);

    long long a, b;
    cin >> a >> b;

    int ans=0;
    for (auto i:prime) {
        int k=2;
        while (true) {
            long long tmp=power(i, k);
            if (tmp>=a && tmp<=b) ans++;
            if (tmp>b || i>=1e5) break;
            k++;
        }
    }
    cout << ans << '\n';

    return 0;
}
