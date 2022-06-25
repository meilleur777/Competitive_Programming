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

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<intp> A(N);
		rep(i, N) cin >> A[i].first >> A[i].second;
		sort(A.begin(), A.end());
		int cut=A[0].second;
		int ans=1;
		for (int i=1; i<N; i++) {
			if (A[i].second<cut) {
				ans++;
				cut=A[i].second;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
