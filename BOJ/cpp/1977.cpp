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

	int M, N;
	cin >> M >> N;
	bool flag = true;
	int sum = 0, minsqr;
	for (int i = M; i <= N; i++) {
		if ((int)pow((int)sqrt(i), 2) == i) {
			if (flag) {
				minsqr = i;
				flag = false;
			}
			sum += i;
		}
	}
	if (!sum) {
		cout << -1;
	}
	else {
		cout << sum << '\n' << minsqr;
	}

	return 0;
}
