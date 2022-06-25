#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int A, B, K;
	cin >> A >> B >> K;
	bool turn=true;
	while (K--) {
		if (turn) {
			if (A%2) A--;
			B+=A/2;
			A/=2;
		}
		else {
			if (B%2) B--;
			A+=B/2;
			B/=2;
		}
		turn=!turn;
	}
	cout << A << ' ' << B;

	return 0;
}
