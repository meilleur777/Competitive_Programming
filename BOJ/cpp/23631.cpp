#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		long long n, k, now=-1, left=0, right=10000;
		cin >> n >> k;
		n--;
		while (left<=right) {
			long long mid=(left+right)/2;
			if (k*mid*(mid+1)/2<=n) {
				left=mid+1;
				now=mid;
			}
			else right=mid-1;
		}
		if (now%2) cout << (now/2+1)*k-(n-k*now*(now+1)/2) << " L\n";
		else cout << -(now/2)*k+(n-k*now*(now+1)/2) << " R\n";
	}

	return 0;
}
