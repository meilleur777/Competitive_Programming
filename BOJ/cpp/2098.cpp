#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    const int inf=0x3f3f3f3f;

	int n;
	cin >> n;
	vector<vector<int>> w(n, vector<int>(n));
	for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
    		cin >> w[i][j];
    		if (w[i][j]==0) w[i][j]=inf;
        }
	}
    
	vector<vector<int>> dp(n, vector<int>((1<<n), inf));
	dp[0][1]=0;
	for (int i=1; i<(1<<n); i++) {
		for (int j=0; j<n; j++) {
			if (!(i&(1<<j))) continue;
			for (int k=0; k<n; k++) {
				if(i&(1<<k)) continue;
				dp[k][i|(1<<k)]=min(dp[k][i|(1<<k)], dp[j][i]+w[j][k]);
			}
		}
	}

	int res=inf;
	for (int i=0; i<n; i++) {
        res=min(res, dp[i][(1<<n)-1]+w[i][0]);
    }
	cout << res;

	return 0;
}
