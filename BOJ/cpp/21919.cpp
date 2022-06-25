#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<bool> isprime(1e6+1, true);
	isprime[0]=isprime[1]=false;
	for (int i=2; i<=1e6; i++) {
		if (!isprime[i]) continue;
		for (int j=i*2; j<=1e6; j+=i) {
			isprime[j]=false;
		}
	}
	vector<int> b;
	while (n--) {
		int a;
		cin >> a;
		if (isprime[a]) b.push_back(a);
	}
	if (b.empty()) cout << -1;
	else {
		ll ans=1;
		b.erase(unique(b.begin(), b.end()), b.end());
		for (auto i:b) ans*=i;
		cout << ans;
	}

	return 0;
}
