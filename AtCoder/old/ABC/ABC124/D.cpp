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

	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;
	int row = 1;
	vector<int> A;
	if (S[0] == '0') {
		A.push_back(0);
	}
	char memo = S[0];
	for (int i = 1; i < N; i++) {
		if (S[i] == memo) {
			row++;
		}
		else {
			memo = S[i];
			A.push_back(row);
			row = 1;
		}
	}
	if (row != 0) {
		A.push_back(row);
	}
	int left = 0, right = 0;
	int sum = 0, ans = -1;
	while (true) {
		while (right-left < 2*K+1 && right < A.size()) {
			sum += A[right];
			right++;
		}
		ans = max(ans, sum);
		if (A.size() == right) {
			break;
		}
		while (right-left > 2*K-1) {
			sum -= A[left];
			left++;
		}
	}
	cout << ans;

	return 0;
}
