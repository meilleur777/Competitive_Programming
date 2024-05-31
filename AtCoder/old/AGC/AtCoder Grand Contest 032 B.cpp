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
	set<intp> st;
	if (n%2) {
		for (int i=1; i<=n/2; i++) {
			st.insert({i, n-i});
		}
	}
	else {
		for (int i=1; i<=n/2; i++) {
			st.insert({i, n-i+1});
		}
	}
	vector<intp> ans;
 	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			if (st.find({i, j})!=st.end()) continue;
			st.insert({i, j});
			ans.push_back({i, j});
		}
	}
	cout << ans.size() << '\n';
	for (auto i:ans) {
		cout << i.first << ' ' << i.second << '\n';
	}

	return 0;
}
