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

	int N, M, K;
	cin >> N >> M >> K;
	int c=min(N/2, M);
	K-=(N-2*c)+M-c;
	if (K<=0) {
		cout << c;
		return 0;
	}
	while (K>0) {
		K-=3;
		c--;
	}
	cout << max(c, 0);

	return 0;
}
