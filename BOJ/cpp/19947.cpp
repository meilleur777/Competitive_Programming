#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	ll h, y;
	cin >> h >> y;
	vector<int> dp(y+1, 0);
	dp[0]=h;

	for (int i=1; i<=y; i++) {
		dp[i]=(int)(dp[i-1]*1.05);	
		if (i>=5) {
			dp[i]=max(dp[i], (int)(dp[i-5]*1.35));
		}
		if (i>=3) {
			dp[i]=max(dp[i], (int)(dp[i-3]*1.2));	
		}
	}
	cout << dp[y];

	return 0;
}
