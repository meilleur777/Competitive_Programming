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

	int N;
	cin >> N;
	vector<ll> A(N);
	rep(i, N) cin >> A[i];
	sort(A.begin(), A.end(), greater<ll>());
	ll sum=0;
	for (int i=0; i<N; i++) {
		sum+=max(0LL, A[i]-i);
	}
	cout << sum;

	return 0;
}
