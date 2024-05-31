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
	vector<int> L(N);
	int m=-1, sum=0;
	rep(i, N) {
		cin >> L[i];
		m=max(m, L[i]);
		sum+=L[i];
	}
	if (sum-m>m) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}
