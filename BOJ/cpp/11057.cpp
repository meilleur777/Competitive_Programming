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

const int mod = 10007;

int main() {
	init_code();

	int N;
	cin >> N;
	int A[10][1001] = { 0 };
	for (int i = 0; i < 10; i++) {
		A[i][1] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				A[k][i] += A[j][i-1];
				A[k][i] %= mod;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += A[i][N];
		ans %= mod;
	}
	cout << ans;

	return 0;
}
