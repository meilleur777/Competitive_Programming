#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0]=false;
    isPrime[1]=false;
    for (int i=2; i<=n; i++) {
        if (isPrime[i]==false) continue;
        for (int j=i*2; j<=n; j+=i) {
            isPrime[j]=false;
        }
    }
    int ret=0;
    for (auto i:isPrime) ret+=i;
    return ret;
}