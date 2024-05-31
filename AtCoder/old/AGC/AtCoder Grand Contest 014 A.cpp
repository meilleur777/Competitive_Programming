#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
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

	int a, b, c;
	cin >> a >> b >> c;
	int cnt=0;
	if (a&1 || b&1 || c&1) {
		cout << 0;
		return 0;
	}
	if (a==b && b==c) {
		cout << -1;
		return 0;
	}
	while (true) {
		if (a&1 || b&1 || c&1) break;
		int ta=a/2;
		int tb=b/2;
		int tc=c/2;
		a=tb+tc;
		b=ta+tc;
		c=ta+tb;
		cnt++;
	}
	cout << cnt;

	return 0;
}
