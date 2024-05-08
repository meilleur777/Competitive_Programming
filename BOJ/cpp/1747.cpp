#include <bits/stdc++.h>
using namespace std;

const int bound=1003001;
vector<int> primes;
vector<bool> isPrime(bound+1, true);

void sieve() {
	isPrime[0]=isPrime[1]=false;
	for (int i=2; i<=bound; i++) {
		if (isPrime[i]) {
            primes.push_back(i);
    		for (int j=i*2; j<=bound; j+=i) {
    			isPrime[j]=false;
    		}
        }
	}
}

bool isPal(int a) {
	string s=to_string(a);
    int n=s.size();
	for (int i=0; i<n/2; i++) {
		if (s[i]!=s[n-i-1]) {
			return false;
		}
	}

	return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

	sieve();

	int n;
	cin >> n;
	auto it=lower_bound(primes.begin(), primes.end(), n);

	while (true) {
		if (isPal(*it)) {
			cout << *it;
			break;
		}
		it++;
	}

	return 0;
}
