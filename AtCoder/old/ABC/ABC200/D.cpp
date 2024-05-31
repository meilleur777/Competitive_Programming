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
	rep(i, N) {
		cin >> A[i];
		A[i]%=200;
	}
	int cei=min(N, 8);
	vector<vector<int> > can(200);
	for (int i=0; i<(1<<cei); i++) {
		int tmp=0;
		vector<int> tv;
		for (int j=0; j<cei; j++) {
			if (i&(1<<j)) {
				tv.push_back(j+1);
				tmp+=A[j];
				tmp%=200;
			}
		}
		if (tv.empty()) continue;
		if (!can[tmp].empty()) {
			cout << "Yes\n";
			cout << can[tmp].size() << ' ';
			for (auto k:can[tmp]) {
				cout << k << ' ';
			}
			cout << '\n';
			cout << tv.size() << ' ';
			for (auto k:tv) {
				cout << k << ' ';
			}
			return 0;
		}
		else {
			can[tmp]=tv;
		}
	}
	cout << "No";

	return 0;
}
