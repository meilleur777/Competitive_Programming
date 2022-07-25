#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<intp> a(n);
	rep(i, n) cin >> a[i].first >> a[i].second;

	if (!n) {
		cout << 0;
		return 0;
	}

	priority_queue<int> pq;
	sort(a.begin(), a.end(), [&](intp& p, intp& q) {
		return p.second<q.second;
	});
	int now=a.back().second;
	int ptr=n-1;
	int ans=0;
	while (true) {
		if (!now) break;
		while (ptr>=0 && a[ptr].second>=now) { 
			pq.push(a[ptr].first);
			ptr--;
		}
		if (!pq.empty()) {
			ans+=pq.top();
			pq.pop();
		}
		now--;
	}
	cout << ans;

	return 0;
}
