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

const ll mod = 1e9+7;

int main() {
	init_code();

	int N;
	cin >> N;
	vector<ll> A(N);
	ll psum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		psum += A[i];
		psum %= mod;
	}
	ll sum = 0;
	for (int i = 0; i < N - 1; i++) {
		psum -= A[i];	
		if (psum < 0) psum += mod;
		sum += psum*A[i];
		sum %= mod;
	}
	cout << sum;

	return 0;
}
