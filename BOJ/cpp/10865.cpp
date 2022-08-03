#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> cnt(n, 0);
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		cnt[a]++;
		cnt[b]++;
	}
	for (auto i:cnt) cout << i << '\n';

	return 0;
}
