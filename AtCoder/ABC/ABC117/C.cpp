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
	vector<ll> A(M), B;
	rep(i, M) cin >> A[i];
	sort(A.begin(), A.end());
	ll sum=0;
	for (int i=0; i<M-1; i++) {
		B.push_back(A[i+1]-A[i]);
		sum+=B[i];
	}
	sort(B.begin(), B.end(), greater<int>());
	for (int i=0; i<B.size() && i<N-1; i++) {
		sum-=B[i];
	}
	cout << sum;

	return 0;
}
