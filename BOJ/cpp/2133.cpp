#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> dp(n+1, 0);
	dp[0]=1;
	dp[2]=3;
	for (int i=4; i<=n; i+=2) {
		dp[i]=dp[i-2]*3;
		for (int j=i-4; j>=0; j-=2) {
			dp[i]+=dp[j]*2;
		}
	}
	cout << dp[n];

	return 0;
}
