#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (int i=0; i<n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	auto cpr=[&](int a, int b) {
		return v[a].second>v[b].second;
	};
	priority_queue<int, vector<int>, decltype(cpr)> pq(cpr);

	sort(v.begin(), v.end(), [&](const pair<int, int>& p, const pair<int, int>& q) {
		return p.second<q.second;
	});

	for (int i=0; i<n; i++) {
		pq.push(i);
	}

	long long ans=0;
	long long now=0;
	for (int i=0; i<n; i++) {
		while (!pq.empty() && v[i].second+2*k>=v[pq.top()].second) {
			now+=v[pq.top()].first;
			pq.pop();
		}

		ans=max(ans, now);

		now-=v[i].first;
	}

	cout << ans;

	return 0;
}
