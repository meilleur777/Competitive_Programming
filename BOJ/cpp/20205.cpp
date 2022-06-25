#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
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

int res[101][101];

int main() {
	init_code();

	int N, K;
	cin >> N >> K;
	rep(i, N) rep(j, N) {
		int x;
		cin >> x;
		for (int k=i*K; k<(i+1)*K; k++) {
			for (int l=j*K; l<(j+1)*K; l++) {
				res[k][l]=x;
			}
		}
	}
	rep(i, N*K) {
		rep(j, N*K) {
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
