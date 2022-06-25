#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	string s;
	cin >> s;
	vector<vector<int>> dp(3, vector<int>(s.size(), 1));
	dp[1][0]=1;
	for (int i=1; i<s.size(); i++) {
		if (i-3>=0) dp[1][i]=max(dp[1][i], dp[2][i-1]+1);
		if (i-2>=0) dp[2][i]=max(dp[2][i], dp[1][i-2]+1);
		if (s[i]!=s[i-1]) dp[1][i]=max(dp[1][i], dp[1][i-1]+1);
		if (i-3>=0 && s.substr(i-3, 2)!=s.substr(i-1, 2)) 
			dp[2][i]=max(dp[2][i], dp[2][i-2]+1);
	}
	cout << max(dp[1].back(), dp[2].back());

	return 0;
}
