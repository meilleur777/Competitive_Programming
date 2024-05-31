#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
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

	ll N;
	cin >> N;
	vector<ll> A(5);
	rep(i, 5) cin >> A[i];
	ll temp = *min_element(A.begin(), A.end());
	cout << 4+(N+temp-1)/temp;

	return 0;
}
