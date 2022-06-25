#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		vector<pair<ll, ll>> pnt(4);
		rep(i, 4) cin >> pnt[i].first >> pnt[i].second;
		sort(pnt.begin(), pnt.end());
		auto dis=[&](int a, int b) {
			ll p=(pnt[a].first-pnt[b].first)*(pnt[a].first-pnt[b].first);
			ll q=(pnt[a].second-pnt[b].second)*(pnt[a].second-pnt[b].second);
			return p+q;
		};
		cout << (dis(0, 1)==dis(1, 3) && dis(1, 3)==dis(3, 2) && dis(3, 2)==dis(2, 0) && dis(0, 3)==dis(1, 2)) << '\n';
	}

	return 0;
}
