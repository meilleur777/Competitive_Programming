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

	int N, a, b;
	cin >> N >> a >> b;
	int cnt=0;
	while (true) {
		if (a==b) {
			cout << cnt;
			return 0;
		}
		a=(a+1)/2;
		b=(b+1)/2;
		cnt++;
	}

	return 0;
}
