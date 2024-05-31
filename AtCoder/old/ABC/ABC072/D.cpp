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

	int N;
	cin >> N;
	vector<int> p(N+1);
	rep(i, N) cin >> p[i+1];
	int cnt = 0;
	for (int i = 1; i < N; i++) {
		if (p[i] == i) {
			swap(p[i], p[i+1]);
			cnt++;
		}
	}	
	if (p[N] == N) {
		cnt++;
	}
	cout << cnt;

	return 0;
}
