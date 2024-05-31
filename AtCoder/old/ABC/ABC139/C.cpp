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

	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}

	vector<int> ans(N);
	ans[0] = 1;
	for (int i = 1; i < N; i++) {
		if (H[i - 1] >= H[i]) {
			ans[i] = ans[i - 1] + 1;
		}	
		else {
			ans[i] = 1;
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans[N - 1] - 1;

	return 0;
}

