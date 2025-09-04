#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<bool> chk(n+1, false);

	while (m--) {
		int k;
		cin >> k;
		for (int i=k; i<=n; i+=k) {
			chk[i]=true;
		}
	}

	long long ans=0;
	for (int i=1; i<=n; i++) {
		if (chk[i]) {
			ans+=i;
		}
	}

	cout << ans;

	return 0;
}
