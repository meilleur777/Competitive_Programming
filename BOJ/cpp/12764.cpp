#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i=0; i<n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());

	auto cpr=[&](const pair<int, int> p, const pair<int, int> q) {
		return p.second>q.second;
	};
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cpr)> pq(cpr);

	auto cpr2=[&](int a, int b) {
		return a>b;
	};
	priority_queue<int, vector<int>, decltype(cpr2)> pq2(cpr2);

	vector<int> num(n, -1);
	for (int i=0; i<n; i++) {
		while (!pq.empty() && pq.top().second<v[i].first) {
			pq2.push(pq.top().first);
			pq.pop();
		}

		if (pq2.empty()) {
			num[i]=(int)pq.size()+1;
		}
		else {
			num[i]=pq2.top();
			pq2.pop();
		}

		pq.push(make_pair(num[i], v[i].second));
	}

	int x=0;
	map<int, int> mp;
	for (auto i:num) {
		mp[i]++;
		x=max(x, i);
	}

	cout << x << '\n';
	int now=1;
	while (mp.find(now)!=mp.end()) {
		cout << mp[now] << ' ';
		now++;
	}

	return 0;
}
