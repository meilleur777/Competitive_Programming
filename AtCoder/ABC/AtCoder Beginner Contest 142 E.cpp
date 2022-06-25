#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	vector<int> A(M+1);
	vector<vector<int> > C(M+1);
	for (int i=1; i<=M; i++) {
		int B;
		cin >> A[i] >> B;
		while (B--) {
			int c;
			cin >> c;
			C[i].push_back(c);
		}
	}
	vector<vector<int> > dp((M+1), vector<int>((1<<N), INF));
	dp[0][0]=0;
	for (int i=1; i<=M; i++) {
		for (int j=0; j<(1<<N); j++) {
			int temp=j;
			for (auto k : C[i]) {
				temp|=(1<<(k-1));
			}
			dp[i][j]=min(dp[i][j], dp[i-1][j]);
			dp[i][temp]=min(dp[i][temp], dp[i-1][j]+A[i]);
		}
	}
	if (dp[M][(1<<N)-1]==INF) {
		cout << -1;
	}
	else {
		cout << dp[M][(1<<N)-1];
	}

	return 0;
}
