#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

ll ans=0;

void sol(ll now, vector<int> w) {
	int siz=w.size();
	if (siz==2) {
		ans=max(ans, now);
		return;
	}
	for (int i=1; i<siz-1; i++) {
		vector<int> tmp;
		rep(j, siz) {
			if (j==i) continue;
			tmp.push_back(w[j]);
		}
		sol(now+w[i-1]*w[i+1], tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> w(n);
	rep(i, n) cin >> w[i];
	sol(0, w);
	cout << ans;

	return 0;
}
