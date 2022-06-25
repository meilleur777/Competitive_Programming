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

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	rep(i, N) cin >> A[i];
	vector<int> cnt(N, 0);
	int res=N;
	for (int i=0; i<M; i++) {
		cnt[A[i]]++;
	}
	for (int i=0; i<N; i++) {
		if (cnt[i]==0) {
			res=i;
			break;
		}
	}
	for (int i=1; i<N-M+1; i++) {
		cnt[A[i-1]]--;
		cnt[A[i+M-1]]++;
		if (cnt[A[i-1]]==0) {
			res=min(res, A[i-1]);
		}
	}
	cout << res;

	return 0;
}
