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

int ans = 0;

int main() {
	init_code();

	int A, B, C, X;
	cin >> A >> B >> C >> X;
	X /= 50;
	int cnt = 0;
	for (int i = 0; i <= A; i++) {
		for (int j = 0; j <= B; j++) {
			for (int k = 0; k <= C; k++) {
				if (X == i*10+j*2+k) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;

	return 0;
}
