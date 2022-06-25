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
	vector<int> A(N);
	rep(i, N) cin >> A[i];
	sort(A.begin(), A.end());
	vector<int> B;
	int sum=0;
	for (int i=0; i<A.size()-1; i++) {
		B.push_back(A[i+1]-A[i]);
		sum+=B[i];
	}
	sort(B.begin(), B.end());
	K--;
	while (K-- && !B.empty()) {
		cout << B.back() << '\n';
		sum-=B.back();
		B.pop_back();
	}
	cout << sum;

	return 0;
}
