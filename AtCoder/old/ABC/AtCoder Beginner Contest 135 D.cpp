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

	string S;
	cin >> S;
	reverse(S.begin(), S.end());
	int tmp=1;
	vector<vector<int> > dp(13, vector<int>(S.size(), 0));
	if (S[0]=='?') {
		rep(i, 10) dp[i][0]++;
	}
	else {
		dp[S[0]-'0'][0]++;
	}
	tmp=10;
	for (int i=1; i<S.size(); i++) {
		if (S[i]=='?') {
			for (int j=0; j<10; j++) {
				int rem=tmp*j%13;
				for (int k=0; k<13; k++) {
					dp[(k+rem)%13][i]+=dp[k][i-1];
					dp[(k+rem)%13][i]%=mod;
				}
			}
		}
		else {
			int rem=tmp*(S[i]-'0')%13;
			for (int j=0; j<13; j++) {
				dp[(j+rem)%13][i]+=dp[j][i-1];
				dp[(j+rem)%13][i]%=mod;
			}
		}
		tmp*=10;
		tmp%=13;
	}
	cout << dp[5][S.size()-1];

	return 0;
}
