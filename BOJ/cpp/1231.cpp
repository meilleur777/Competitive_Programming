#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int c, d, m;
	cin >> c >> d >> m;
	vector<vector<int>> v(c, vector<int>(d));
	rep(i, c) rep(j, d) cin >> v[i][j];
	vector<int> dp;
	for (int i=1; i<d; i++) {
		dp=vector<int>(m+1, 0);
		for (int j=0; j<c; j++) {
			for (int k=v[j][i-1]; k<=m; k++) {
				dp[k]=max(dp[k], dp[k-v[j][i-1]]+v[j][i]-v[j][i-1]);
			}	
		}		
		m+=dp[m];
	}
	cout << m;

	return 0;
}
