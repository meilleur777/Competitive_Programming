#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

vector<int> minFactor(1e7 + 1);
vector<int> cntMinFactor(1e7 + 1);
vector<int> cntFactor(1e7 + 1, 0);

/*get minimum factor of i using eratosthenes's sieve*/
void getMinFactor() {
	minFactor[0] = 1;
	for (int i = 1; i <= 1e7; i++) {
		minFactor[i] = i;
	}
	for (int i = 2; i*i <= 1e7; i++) {
		if (minFactor[i] != i) {
			continue;
		}		
		for (int j = i*i; j <= 1e7; j += i) {
			if (minFactor[j] == j){
				minFactor[j] = i;
			}
		}
	}
}

void calc() {
	cntFactor[1] = 1;
	for (int i = 2; i <= 1e7; i++) {
		/*if i is prime number*/
		if (minFactor[i] == i) {
			cntMinFactor[i] = 1;
			cntFactor[i] = 2;
		}
		/*else if i is composite number*/
		else {
			int temp = i/minFactor[i];
			if (minFactor[i] != minFactor[temp]) {
				cntMinFactor[i] = 1;
			}
			else {
				cntMinFactor[i] = cntMinFactor[temp]+1;
			}
			cntFactor[i] = (cntFactor[temp]/cntMinFactor[i])*(cntMinFactor[i]+1);
		}
	}
}

int main() {
	fast_io;

	getMinFactor();
	calc();

	int C;
	cin >> C;
	while (C--) {
		int n, lo, hi;
		cin >> n >> lo >> hi;
		int ans = 0;
		for (int i = lo; i <= hi; i++) {
			if (cntFactor[i] == n) {
				ans++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
