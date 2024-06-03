#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b) {
    if (b==0) return 1LL;
    long long tmp=power(a, b/2);
    tmp=tmp*tmp;
    if (b%2) return tmp*a;
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    vector<long long> prime;
    vector<bool> isPrime(1e7+1, true);
    isPrime[0]=isPrime[1]=false;
    for (int i=2; i<=1e7; i++) {
        if (!isPrime[i]) continue;
        prime.push_back(i);
        for (int j=i*2; j<=1e7; j+=i) {
            isPrime[j]=false;
        }
    }

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
    cout << ans;

    return 0;
}
