#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

ll power(ll a, ll b) {
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=power(a, b/2);
	tmp=tmp*tmp;
	if (b%2) return tmp*a;
	return tmp;
}

int main() {
	ll s, left, right, n;
	cin >> s >> left >> right >> n;

	int nxt[3][3]={
		{0, 2, 1},
		{1, 0, 0},
		{1, 2, 1}
	};

	//root, level, num
	vector<vector<vector<ll>>> dp(3, vector<vector<ll>>(21, vector<ll>(3, 0)));
	rep(i, 3) dp[i][0][i]=1;
	for (int level=1; level<=20; level++) {
		rep(i, 3) {
			dp[i][level][0]=dp[i][level-1][0]+dp[i][level-1][1]*2;
			dp[i][level][1]=dp[i][level-1][0]+dp[i][level-1][1]+dp[i][level-1][2]*2;
			dp[i][level][2]=dp[i][level-1][0]+dp[i][level-1][2];
		}
	}

	int ans[3]={0};
	function<void(int, ll, ll)> sol=[&](int root, ll start, ll end) {
		if (right<start || left>end) return;
		ll width=(end-start+1)/3;
		if (left<=start && end<=right) {
			int cnt=0;
			for (; width; cnt++, width/=3);
			rep(i, 3) ans[i]+=dp[root][cnt][i];
		}
		else rep(i, 3) sol(nxt[root][i], start+width*i, start+width*(i+1)-1);
	};

	sol(s-1, 0LL, power(3, n)-1);
	rep(i, 3) cout << ans[i] << ' ';

	return 0;
}
