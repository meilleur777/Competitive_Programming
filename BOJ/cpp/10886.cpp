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
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		cnt += x;
	}
	if (cnt > N/2) {
		cout << "Junhee is cute!";
	}
	else {
		cout << "Junhee is not cute!";
	}

	return 0;
}
