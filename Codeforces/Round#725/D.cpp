#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isNoPrime[40002] = { false };
vector<int> primev;

void sieve() {
	isNoPrime[0] = isNoPrime[1] = true;
	
	for (int i = 2; i <= 40000; i++) {
		if (!isNoPrime[i]) primev.push_back(i);
		
		for (int j = i * 2; j <= 40000; j += i) {
			isNoPrime[j] = true;
		}
	}
}

int primes(int x) {
	int count = 0;
	
	for (int i : primev) {
		while (x % i == 0) {
			x /= i;
			count++;
		}
	}
	
	if (x > 1) count++;
	return count;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	sieve();
	
	int T;
	cin >> T;
	while (T--) {
		int a, b, k;
		cin >> a >> b >> k;
		
		
		int mini;
		if (a == b) mini = 0;
		else if (a % b == 0 || b % a == 0) mini = 1;
		else mini = 2;
		
		if (k == 1) {
			if (mini == 1) cout << "Yes\n";
			else cout << "No\n";
		}
		else {
			int prdiva = primes(a);
			int prdivb = primes(b);
			int maximum = prdiva + prdivb;
			
			if (maximum >= k && k >= mini) {
				cout << "Yes\n";
			}
			else cout << "No\n";
		}
	}	
}

