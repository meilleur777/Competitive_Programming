#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	int ans=abs(n-100);
	vector<bool> pos(10, true);
	while (m--) {
		int a;
		cin >> a;
		pos[a]=false;
	}
	for (int i=0; i<1e6; i++) {
		bool flag=true;
		string s=to_string(i);
		for (auto c:s) {
			if (!pos[c-'0']) {
				flag=false;
				break;
			}
		}
		if (flag) ans=min(ans, abs(n-i)+(int)s.size());
	}
	cout << ans;

	return 0;
}
