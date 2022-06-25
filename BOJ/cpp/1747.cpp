#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

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
vector<bool> isPrime(1003001+1, true);

void sieve() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= 1003001; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
		}
		else {
			continue;
		}
		for (int j = i*2; j <= 1003001; j += i) {
			isPrime[j] = false;
		}
	}
}

bool chk(int a) {
	string s = to_string(a);
	for (int i = 0; i < s.size() /2; i++) {
		if (s[i] != s[s.size()-i-1]) {
			return false;
		}
	}
	return true;
}

int main() {
	init_code();

	sieve();
	int N;
	cin >> N;
	vector<int>::iterator it = lower_bound(primes.begin(), primes.end(), N);
	while (true) {
		if (chk(*it)) {
			cout << *it;
			break;
		}
		it++;
	}

	return 0;
}
