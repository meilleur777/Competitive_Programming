#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int i=0; i<n; i++) dp[i][i]=a[i];
	for (int size=1; size<=n; size++) {
		for (int start=0; start+size<n; start++) {
			for (int pivot=start; pivot<start+size; pivot++) {
				int left=dp[start][pivot];
				int right=dp[pivot+1][start+size];
				if (!left || !right) continue;
				if (left!=right) continue;
				dp[start][start+size]=max(dp[start][start+size], left+1);
			}
		}
	}
	
	int ans=0;
	rep(i, n) rep(j, n) ans=max(ans, dp[i][j]);
	cout << ans;

	return 0;
}
