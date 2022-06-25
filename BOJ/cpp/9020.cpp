#include <vector>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<bool> isprime(1e4+1, true);
	isprime[0]=isprime[1]=false;
	for (int i=2; i<=1e4; i++) {
		if (!isprime[i]) continue;
		for (int j=i*2; j<=1e4; j+=i) {
			isprime[j]=false;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i=n/2; i>=2; i--) {
			if (isprime[i] && isprime[n-i]) {
				cout << i << ' ' << n-i << '\n';
				break;
			}
		}
	}

	return 0;
}
