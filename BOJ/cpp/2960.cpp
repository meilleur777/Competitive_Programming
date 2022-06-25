#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

vector<int> primes;
vector<bool> isPrime(1001, true);

void sieve() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= 1e3; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
		}
		else {
			continue;
		}
		for (int j = i*2; j <= 1e3; j += i) {
			isPrime[j] = false;
		}
	}
}

int main() {
	init_code();

	sieve();
	int N, K;
	cin >> N >> K;	
	vector<bool> chk(N+1, true);
	for (auto num : primes) {
		for (int i = num; i <= N; i += num)	{
			if (chk[i]) {
				chk[i] = false;
				K--;
				if (!K) {
					cout << i;
					return 0;
				}
			}
		}
	}

	return 0;
}
