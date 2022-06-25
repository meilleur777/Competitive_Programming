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

	int N, K;
	cin >> N >> K;
	vector<int> h(N);
	rep(i, N) cin >> h[i];
	sort(h.begin(), h.end(), greater<int>());
	int ans=INF;
	for (int i=0; i+K-1<N; i++) {
		ans=min(ans, h[i]-h[i+K-1]);
	}
	cout << ans;

	return 0;
}
