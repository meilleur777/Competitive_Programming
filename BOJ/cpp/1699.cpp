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

int main() {
	init_code();

	int N;
	cin >> N;
	int ans = 0;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; i++) {
		if ((int)pow((int)sqrt(i), 2) == i) {
			A[i] = 1;
		}
		else {
			int res = INT_MAX;
			for (int j = 1; j*j <= i/2; j++) {
				res = min(res, A[j*j] + A[i-j*j]);	
			}
			A[i] = res;
		}
	}
	cout << A[N];

	return 0;
}
