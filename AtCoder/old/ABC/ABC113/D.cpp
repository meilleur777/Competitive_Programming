#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

	int H, W, K;
	cin >> H >> W >> K;
	vector<vector<int> > dp(H+1, vector<int>(W, 0));
	dp[0][0]=1;
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			for (int k=0; k<(1<<(W-1)); k++) {
				bool ok=true;
				for (int l=0; l<W-2; l++) {
					if ((k&(1<<l)) && (k&(1<<(l+1)))) {
						ok=false;
						break;
					}
				}
				if (!ok) continue;
				if (j!=0 && (k&(1<<(j-1)))) {
					dp[i+1][j-1]+=dp[i][j];
					dp[i+1][j-1]%=mod;
				}				
				else if (j!=W-1 && (k&(1<<j))) {
					dp[i+1][j+1]+=dp[i][j];
					dp[i+1][j+1]%=mod;
				}
				else {
					dp[i+1][j]+=dp[i][j];
					dp[i+1][j]%=mod;
				}
			}
		}
	}
	cout << dp[H][K-1];


	return 0;
}
