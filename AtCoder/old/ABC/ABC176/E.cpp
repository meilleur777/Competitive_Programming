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

	int H, W, M;
	cin >> H >> W >> M;
	vector<int> hcnt(H, 0), wcnt(W, 0);
	set<intp> s;
	rep(i, M) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		hcnt[a]++, wcnt[b]++;
		s.insert({a, b});
	}
	vector<int> hcan, wcan;
	int mh=*max_element(hcnt.begin(), hcnt.end());
	int mw=*max_element(wcnt.begin(), wcnt.end());
	rep(i, H) {
		if (hcnt[i]==mh) {
			hcan.push_back(i);
		}
	}
	rep(i, W) {
		if (wcnt[i]==mw) {
			wcan.push_back(i);
		}
	} 
	int ans=mh+mw-1;
	for (auto i:hcan) {
		for (auto j:wcan) {
			int tmp=s.count({i, j});
			if (tmp==0) {
				cout << ans+1;
				return 0;
			}
		}
	}
	cout << ans;

	return 0;
}
