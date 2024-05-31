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

	int n;
	cin >> n;
	vector<string> w(n);
	set<string> m;
	rep(i, n) {
		cin >> w[i];
	}
	for (int i=0; i<n-1; i++) {
		if (m.count(w[i])) {
			cout << "No";
			return 0;
		}
		m.insert(w[i]);
		if (w[i].back()!=w[i+1].front()) {
			cout << "No";
			return 0;
		}
	}
	if (m.count(w[n-1])) {
		cout << "No";
	}
	else cout << "Yes";

	return 0;
}
