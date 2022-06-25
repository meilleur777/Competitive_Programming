#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<ll> sum(1e6+1, 0);
	for (int i=1; i<=1e6; i++) {
		for (int j=i; j<=1e6; j+=i) {
			sum[j]+=i;
		}
	}

	for (int i=1; i<=1e6; i++) {
		sum[i]+=sum[i-1];
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << sum[n] << '\n';
	}

	long double k=0.0;
	for (int i=1; i<=1e6; i++) {
		k+=1e6/(long double)i;
	}
	cout << k;

	return 0;
}
