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

	int N;
	cin >> N;
	vector<int> A(N);
	rep(i, N) cin >> A[i];
	vector<int> dp(N, 0);
	dp[0]=A[0];
	for (int i=1; i<N; i++) {
		dp[i]=A[i];
		for (int j=i-1; j>=0; j--) {
			if (A[j]<A[i]) {
				dp[i]=max(dp[i], dp[j]+A[i]);
			}
		}
	}
	cout << *max_element(dp.begin(), dp.end());

	return 0;
}
