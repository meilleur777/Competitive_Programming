#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, k;
	while (cin >> n >> k) {
		int ans=0;
		int now=0;
		while (true) {
			ans+=n;
			now+=n;
			n=0;
			n+=now/k;
			now%=k;
			if (n==0) break;
		}
		cout << ans << '\n';
	}

	return 0;
}
