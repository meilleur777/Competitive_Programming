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
	vector<int> t(N+1);
	vector<vector<int> > A(N+1);
	rep(i, N) {
		cin >> t[i+1];
		int M;
		cin >> M;
		A[i+1].resize(M);
		rep(j, M) cin >> A[i+1][j];
	}
	vector<int> res(N+1);
	for (int i=1; i<=N; i++) {
		res[i]=t[i];
		for (auto j : A[i]) {
			res[i]=max(res[i], res[j]+t[i]);
		}
	}
	cout << *max_element(res.begin(), res.end());

	return 0;
}
