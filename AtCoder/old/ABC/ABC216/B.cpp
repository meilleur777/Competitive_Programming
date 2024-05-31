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
	vector<pair<string, string> > A(N);
	rep(i, N) {
		cin >> A[i].first >> A[i].second;
	}
	for (int i=0; i<N; i++) {
		for (int j=i+1; j<N; j++) {
			if (A[i]==A[j]) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";

	return 0;
}
