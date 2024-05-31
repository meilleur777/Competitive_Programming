#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const ll mod=998244353;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<vector<ll>> dp(n, vector<ll>(3001, 0));
	vector<vector<ll>> psum(n, vector<ll>(3001, 0));
	for (int i=a[0]; i<=b[0]; i++) dp[0][i]=1;
	for (int i=1; i<n; i++) {
		psum[i][0]=dp[i-1][0];
		for (int j=1; j<=3000; j++) {
			psum[i][j]+=dp[i-1][j]+psum[i][j-1];
			psum[i][j]%=mod;
		}
		for (int j=a[i]; j<=b[i]; j++) {
			dp[i][j]+=psum[i][j];
			dp[i][j]%=mod;
			// cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
		}
	}	
	ll ans=0;
	for (int j=a[n-1]; j<=b[n-1]; j++) {
		ans+=dp[n-1][j];
		ans%=mod;
	}
	cout << ans;

	return 0;
}
