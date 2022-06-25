#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<bool> isprime(1e6+1, true);
	isprime[0]=isprime[1]=false;
	for (int i=2; i<1e6+1; i++) {
		if (!isprime[i]) continue;
		for (int j=i*2; j<1e6+1; j+=i) {
			isprime[j]=false;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n, ans=0;
		cin >> n;
		for (int i=2; i<=n/2; i++) {
			ans+=isprime[i]&&isprime[n-i];
		}
		cout << ans << '\n';
	}

	return 0;
}
