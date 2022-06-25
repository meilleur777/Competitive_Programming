#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> dp(n, 1);
	for (int i=1; i<n; i++) {
		for (int j=i-1; j>=0; j--) {
			if (a[j]>a[i]) {
				dp[i]=max(dp[i], 1+dp[j]);
			}
		}
	}
	cout << *max_element(dp.begin(), dp.end());

	return 0;
}
