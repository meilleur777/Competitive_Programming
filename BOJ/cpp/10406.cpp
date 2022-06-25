#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int w, n, p;
	cin >> w >> n >> p;
	int ans=0;
	while (p--) {
		int h;
		cin >> h;
		ans+=w<=h && h<=n;
	}
	cout << ans;

	return 0;
}
