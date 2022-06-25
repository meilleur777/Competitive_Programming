#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

vector<bool> isprime(1e5, true); 

void sieve() {
	isprime[0] = isprime[1] = false;
	
	for (int i = 2; i <= 1e5; i++) {
		for (int j = i * 2; j <= 1e5; j += i) {
			isprime[j] = false;		
		}
	}
}

int K, M;
vector<int> cand;
bool chk[10] = { false };

void makecand(int now, int sum) {
	if (now == K) {
		cand.push_back(sum);
		return;
	}
	
	for (int i = 0; i < 10; i++) {
		if (now == K - 1 && !i) continue;
		
		if (!chk[i]) {
			chk[i] = true;
			makecand(now + 1, sum + i * (int)pow(10, now));
			chk[i] = false;
		}
	}
}

bool pos1(int n) {
	for (int i = 2; i < n / 2; i++) {
		if (isprime[i] && isprime[n - i]) {
			return true;
		}
	}
	return false;
}

bool pos2(int n) {
	while (n % M == 0) {
		n /= M;
	}
	
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0 && isprime[i] && isprime[n / i]) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	sieve();	
	
	cin >> K >> M;
	
	makecand(0, 0);
	
	int ans = 0;
	for (int i : cand) {
		if (pos1(i) && pos2(i)) {
			ans++;
		}
	}
	cout << ans;
}

