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

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	a*=100, b*=100;
	vector<intp> dp(f+1, make_pair(-1, -1));
	dp[a]={a, 0};
	dp[b]={b, 0};
	intp ans={-1, -1};
	auto smx=[&](intp& a, const intp& b) {
		if (a==make_pair(-1, -1)) a=b;
		a=(a.first*b.second<a.second*b.first)?a:b;
	};
	for (int i=a; i<=f; i++) {
		if (dp[i]==make_pair(-1, -1)) continue;
		int wat=dp[i].first, sug=dp[i].second;
		// cout << wat << ' ' << sug << '\n';
		if (wat+a<=f) smx(dp[wat+a], {wat+a, sug});
		if (wat+b<=f) smx(dp[wat+b], {wat+b, sug});
		if (wat+c<=f && e*(wat-sug)>=(sug+c)*100) smx(dp[wat+c], {wat+c, sug+c});
		if (wat+d<=f && e*(wat-sug)>=(sug+d)*100) smx(dp[wat+d], {wat+d, sug+d});
		smx(ans, dp[i]);
	}
	cout << ans.first << ' ' << ans.second;

	return 0;
}
