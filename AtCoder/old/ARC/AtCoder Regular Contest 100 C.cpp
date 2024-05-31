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
	rep(i, N) {
		cin >> A[i];
		A[i]-=i+1;
	}
	sort(A.begin(), A.end());
	ll sum=0, mid=A[A.size()/2];
	for (auto i : A) {
		sum+=abs(mid-i);
	}
	cout << sum;

	return 0;
}
