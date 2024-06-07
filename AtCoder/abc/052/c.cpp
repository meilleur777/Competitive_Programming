#include <bits/stdc++.h>
using namespace std;

void sieve(int bound, vector<int>& prime) {
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

    int bound=1e3;
    vector<int> prime;
    sieve(bound, prime);
    
    int n;
    cin >> n;
    vector<int> cnt(bound+1, 0);
    for (int i=1; i<=n; i++) {
        int tmp=i;
        for (auto j:prime) {
            while (tmp%j==0) {
                tmp/=j;
                cnt[j]++;
            }
        }
        cnt[tmp]++;
    }

    long long ans=1;
    const long long mod=1e9+7;
    for (auto j:prime) {
        ans=(ans*(cnt[j]+1))%mod;
    }
    cout << ans;

    return 0;
}
