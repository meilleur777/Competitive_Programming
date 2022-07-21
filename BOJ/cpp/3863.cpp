#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	while (true) {
		int n, m;
		cin >> n >> m;
		if (!n && !m) break;
		vector<intp> info;
		while (n--) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			info.push_back({c, c+d});
		}
		while (m--) {
			int a, b;
			cin >> a >> b;
			int ans=0;
			for (auto i:info) {
				ans+=!(i.first>=a+b || i.second<=a);
			}
			cout << ans << '\n';
		}
	}

	return 0;
}
