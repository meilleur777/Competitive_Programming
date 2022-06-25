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

	int n;
	cin >> n;
	int ans=0;
	for (int i=1; i<=n; i+=2) {
		int cnt=0;
		for (int j=1; j*j<=i; j++) {
			if (i%j==0) cnt+=2;
			if (j*j==i && i%j==0) cnt--;
		}
		if (cnt==8) ans++;
	}
	cout << ans;

	return 0;
}
