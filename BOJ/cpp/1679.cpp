#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int k;
	cin >> k;
	vector<bool> dp(500500+1, false);
	dp[0]=true;
	for (int i=0; i<k; i++) {
		for (int l=500500; l>=0; l--) {
			for (int j=0; j<n; j++) {
				if (l-a[j]<0) break;
				dp[l]=dp[l]||dp[l-a[j]];
			}
		}
	}
	for (int i=0; i<=500500; i++) {
		if (!dp[i]) {
			if (i%2) cout << "jjaksoon";
			else cout << "holsoon";
			cout << " win at " << i;
			return 0;
		}
	}

	return 0;
}
