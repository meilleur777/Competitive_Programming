#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, d;
	cin >> n >> d;
	vector<vector<int>> stc(n, vector<int>(3, 0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<3; j++) {
			cin >> stc[i][j];
		}
	}

	int ans=0x3f3f3f3f;
	for (int i=0; i<(1<<n); i++) {
		map<int, pair<int, int>> mp;
		for (int j=0; j<n; j++) {
			if ((i&(1<<j))) {
				if (stc[j][1]>d) continue;
				mp.insert({stc[j][0], {stc[j][1], stc[j][2]}});
			}
		}

		int now=0;
		int cost=0;

		while (now<d) {
			if (mp.find(now)!=mp.end()) {
				int nxt=mp[now].first;
				cost+=mp[now].second;
				now=nxt;
			}
			else {
				cost++;
				now++;
			}
		}
		
		ans=min(cost, ans);
	}

	cout << ans;

	return 0;
}
