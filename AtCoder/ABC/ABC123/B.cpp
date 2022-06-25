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

int main() {
	init_code();

	vector<int> A(5);
	int mV = 10, mI;
	rep(i, 5) {
		cin >> A[i];
		if (A[i]%10 > 0 && A[i]%10 < mV) {
			mV = A[i]%10;
			mI = i;
		}
	}
	int sum = 0;
	rep(i, 5) {
		if (mV != 10 && i == mI) {
			sum += A[i];
		}
		else {
			sum += (A[i]+9)/10*10;
		}
	}
	cout << sum;

	return 0;
}
