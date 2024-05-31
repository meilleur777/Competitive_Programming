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

	int N, M, C;
	cin >> N >> M >> C;
	vector<int> B(M);
	rep(i, M) {
		cin >> B[i];
	}
	int ans = 0;
	rep(j, N) {
		int sum = 0;
		rep(i, M) {
			int x;
			cin >> x;
			sum += x*B[i];
		}
		ans += (sum+C > 0);
	}
	cout << ans;

	return 0;
}
