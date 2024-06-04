#include <bits/stdc++.h>
using namespace std;

void eratosthenes(int bound, vector<int>& spf) {
    spf=vector<int>(bound+1, 1);
    spf[0]=0;

    for (int i=2; i<=bound; i++) {
        if (spf[i]!=1) continue;

        for (int j=i; j<=bound; j+=i) {
            if (spf[j]!=1) continue;
            spf[j]=i;
        }
    }
}

//Calculate the prime factorization using O(n) space and O(log n) time complexity 
//with pre-computation (Sieve of Eratosthenes)
vector<int> factorization(int num, const vector<int>& spf) {
    vector<int> ret;
    while (num!=1) {
        ret.push_back(spf[num]);
        num/=spf[num];
    }
    return ret;
}

int main() {
    const int bound=1e5;
    vector<int> spf;
    eratosthenes(bound, spf);

    int x=12246;
    cout << "Prime factor for x is : ";
    vector<int> p=factorization(x, spf);
    for (auto i:p) cout << i << ' ';

    return 0;
}
