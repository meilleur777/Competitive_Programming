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

	int N;
	cin >> N;
	vector<int> A(N);
	rep(i, N) cin >> A[i];
	int ans=INT_MAX;
	for (int i=0; i<(1<<(N-1)); i++) {
		int tres=0;
		int tmp=0;
		for (int j=0; j<N; j++) {
			tmp|=A[j];
			if (i&(1<<j)) {
				tres^=tmp;
				tmp=0;
			}
		}
		tres^=tmp;
		ans=min(ans, tres);
	}
	cout << ans;

	return 0;
}
