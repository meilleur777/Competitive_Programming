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

vector<int> getPrimeFactor(int x) {
	vector<int> ret;
	for (int i = 2; i*i <= x; i++) {
		while (x%i == 0) {
			x /= i;
			ret.push_back(i);	
		}
	}
	if (x != 1) {
		ret.push_back(x);
	}
	return ret;
}

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<bool> cand(M + 1, true);
	for (int i = 0; i < N; i++) {
		vector<int> primes = getPrimeFactor(A[i]);
		for (auto k : primes) {
			if (cand[k]) {
				for (int j = k; j <= M; j += k) {
					cand[j] = false;
				}
			}
		}
	}
	vector<int> res;
	for (int i = 1; i <= M; i++) {
		if (cand[i]) {
			res.push_back(i);
		}
	}
	cout << res.size() << '\n';
	for (int i : res) {
		cout << i << '\n';
	}

	return 0;
}
