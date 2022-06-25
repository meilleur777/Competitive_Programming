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

vector<int> primeFactors;

int gcd(int a, int b) {
	if (a%b == 0) return b;
	else return gcd(b, a%b);
}

void getPrimeFactor(int x) {
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0) {
			primeFactors.push_back(i);
			while (x%i == 0) {
				x /= i;
			}			
		}
	}
	if (x != 1) {
		primeFactors.push_back(x);
	}
}

int main() {
	init_code();

	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		getPrimeFactor(A[i]);
	}
	int temp = primeFactors.size();
	sort(primeFactors.begin(), primeFactors.end());
	primeFactors.erase(unique(primeFactors.begin(), primeFactors.end()), primeFactors.end());
	if (primeFactors.size() == temp) {
		cout << "pairwise coprime";
		return 0;
	}

	int a = A[0];
	for (int i = 1; i < N; i++) {
		a = gcd(a, A[i]);
	}
	if (a == 1) {
		cout << "setwise coprime";
	}
	else {
		cout << "not coprime";
	}

	return 0;
}
