#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, c;
	cin >> n >> c;
	vector<vector<intp>> cha(c);
	rep(i, n) {
		int s, t, C;
		cin >> s >> t >> C;
		s*=2, t*=2, C--;
		cha[C].push_back({s, t});
	}
	map<int, int> mp;
	for (auto i:cha) {
		priority_queue<intp, vector<intp>, greater<intp>> pq;
		for (auto j:i) pq.push(j);
		while (!pq.empty()) {
			intp now=pq.top();
			pq.pop();
			while (!pq.empty() && now.second==pq.top().first) {
				now.second=pq.top().second;
				pq.pop();
			}
			mp[now.first-1]++;
			mp[now.second]--;
		}
	}
	int now=0;
	int ans=0;
	for (auto [a, b]:mp) {
		now+=b;
		ans=max(ans, now);
	}
	cout << ans;

	return 0;
}
